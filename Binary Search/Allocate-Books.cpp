// M-1) Brute force --> T.C: O(N * (sum(arr[])-max(arr[])+1)), where N = size of the array
// Gives TLE
/*
int findPages(vector<int>& arr, int n, int m) {
        if(m > n) 
            return -1;
        
        int sumPages = accumulate(arr.begin(), arr.end(), 0);
        int maxPage = *max_element(arr.begin(), arr.end());
        
        for(int i = maxPage; i <= sumPages; i++){ 
            int studentCnt = 1, studentPage = 0;   // first student has 0 pages initially
            for(int j = 0; j < n; j++){
                if(studentPage + arr[j] <= i){
                    studentPage += arr[j];
                }
                else{
                    studentCnt++;
                    studentPage = arr[j];
                }
            }
            
            if(studentCnt == m)         // return the page as soon as student count == m,
                return i;               // so that the minimum possible page is returned immediately
        }
}
*/

// M-2) Better code quality to write M-1 (still will give TLE)
/*
int countStudents(vector<int> &arr, int pages) {
    int n = arr.size(); 
    int students = 1, pagesStudent = 0;   // first student has 0 pages initially
    for (int i = 0; i < n; i++) {
        if (pagesStudent + arr[i] <= pages) {
            pagesStudent += arr[i]; // add pages to current student
        }
        else {
            students++;    
            pagesStudent = arr[i];  // add current page to next student
        }
    }
    
    return students;
}

int findPages(vector<int>& arr, int n, int m) {
    if (m > n)  //book allocation impossible
        return -1;

    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);

    for (int pages = low; pages <= high; pages++) {
        if (countStudents(arr, pages) == m) {
            return pages;
        }
    }
}
*/


// M-3) Binary Search --> T.C: O(N * log(sum(arr[])-max(arr[])+1)), where N = size of the array
int countStudents(vector<int> &arr, int pages) {
    int n = arr.size(); 
    int students = 1, pagesStudent = 0;    // first student has 0 pages initially
    for (int i = 0; i < n; i++) {
        if (pagesStudent + arr[i] <= pages) {
            pagesStudent += arr[i]; // add pages to current student
        }
        else {
            students++;    
            pagesStudent = arr[i];  // add current page to next student
        }
    }
    
    return students;
}

int findPages(vector<int>& arr, int n, int m) {
    if (m > n)  //book allocation impossible
        return -1;

    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);

    while(low <= high) {
        int mid = (low + high) / 2;
        int students = countStudents(arr, mid);
        
        if (students > m) {
            low = mid + 1;   // eliminate left half to reduce the no. of students (pages increases, students decrease)
        }
        else {
            high = mid - 1;
        }
    }

    return low;
}


