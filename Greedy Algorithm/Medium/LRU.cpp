// 1. What is a page fault?

// Suppose RAM has only 3 frames:

// Frame 1
// Frame 2
// Frame 3

// A program requests pages one by one:

// 1  2  3  1  4

// When a requested page is already in RAM → HIT.

// When a requested page is not in RAM → PAGE FAULT.

// First page: 1

// RAM is empty:

// [ _  _  _ ]


// Request: 1

// 1 isn't in RAM.

// Therefore:

// PAGE FAULT

// Put 1 into RAM:

// [ 1  _  _ ]

// Why fault? Because the CPU requested page 1, but page 1 wasn't currently in memory.

// Second page: 2
// RAM = [1 _ _]
// Request = 2

// Is 2 in RAM?

// No.

// Therefore:

// PAGE FAULT

// Put it in:

// [1 2 _]
// Third page: 3
// RAM = [1 2 _]
// Request = 3

// 3 isn't there.

// So:

// PAGE FAULT

// Now:

// [1 2 3]

// At this point RAM is full.

// 2. Now comes the important part

// Next request:

// 1

// RAM currently contains:

// [1 2 3]

// Is 1 already there?

// YES.

// Therefore:

// HIT ✅

// No page fault.

// But something important happened:

// We used page 1 just now.

// So LRU must remember that.

// Think of the usage history:

// 1 → used just now
// 3 → used before that
// 2 → used the longest time ago

// So conceptually:

// Most Recently Used
//         ↓
//         1
//         3
//         2
//         ↑
// Least Recently Used
// 3. Now request 4

// RAM is full:

// [1 2 3]

// Request:

// 4

// Is 4 in RAM?

// No.

// Therefore:

// PAGE FAULT 🚨

// Now we need to make space.

// LRU asks:

// Which page has been used the longest time ago?

// Look at what happened:

// Request sequence:


// 1 → fault
// 2 → fault
// 3 → fault
// 1 → HIT
// 4 → fault

// The most recent usage of each page is:

// Page 1 → just used
// Page 2 → never used again after entering
// Page 3 → never used again after entering

// Between 2 and 3, 2 was used earlier than 3.

// Therefore:

// 2 = Least Recently Used

// So we remove 2, NOT 1.

// Before:


// [1 2 3]


// Remove 2:


// [1 _ 3]


// Insert 4:


// [1 4 3]

// That's LRU.

int pageFaults(vector<int>& pages, int capacity) {
    vector<int> frames;
    int faults = 0;

    for (int page : pages) {

        // Is page already in memory?
        auto it = find(frames.begin(), frames.end(), page);

        if (it != frames.end()) {
            // HIT
            // Move this page to the back because it was
            // just used, so it is now the most recently used.
            frames.erase(it);
            frames.push_back(page);
        }
        else {
            // FAULT
            faults++;

            // If memory is full, remove LRU page
            if (frames.size() == capacity) {
                frames.erase(frames.begin());
            }

            // New page becomes most recently used
            frames.push_back(page);
        }
    }

    return faults;
}