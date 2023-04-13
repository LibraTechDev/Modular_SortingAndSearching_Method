#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
using namespace std;

// bubble sort
void bubbleSort(vector<int> &arr)
{
    int n = arr.size();
    int temp;
    for (int i = 0; i < n; i++)
    {
        for (int h = 0; h < n - 1; h++)
        {
            if (arr[h] > arr[h + 1])
            {
                temp = arr[h];
                arr[h] = arr[h + 1];
                arr[h + 1] = temp;
            }
        }
        cout << endl;
        cout << "Akhir tahap " << i + 1 << " : ";
        for (int a = 0; a < n; a++)
        {
            cout << arr[a] << " ";
        }
    }
    cout << "\n==========================\n";
}

// selection sort
void selectionSort(vector<int> &arr)
{
    int n = arr.size();
    int temp;
    int loc_min;

    for (int i = 0; i < n; i++)
    {
        loc_min = i;
        cout << "Cycle " << i + 1 << ": ";

        for (int j = i; j < n; j++)
        {
            if (arr[j] < arr[loc_min])
            {
                loc_min = j;
            }
        }

        for (int k = 0; k < n; k++)
        {
            cout << arr[k] << " ";
        }

        temp = arr[i];
        arr[i] = arr[loc_min];
        arr[loc_min] = temp;
        cout << endl;
    }
    cout << "====================\n";
}

//  insertion sort
void insertionSort(vector<int> &arr)
{
    int n = arr.size();
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;

        // Menampilkan langkah-langkah
        cout << "Step " << i << ": ";
        for (int k = 0; k < n; k++)
        {
            cout << arr[k] << " ";
        }
        cout << endl;
    }
}
// BogoSort
bool isSorted(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 1; i < n; i++)
    {
        if (arr[i] < arr[i - 1])
        {
            return false;
        }
    }
    return true;
}
void shuffle(vector<int> &arr)
{
    int n = arr.size();
    for (int i = n - 1; i > 0; i--)
    {
        int j = rand() % (i + 1);
        swap(arr[i], arr[j]);
    }
}
void bogosort(vector<int> &arr)
{
    int n = arr.size();
    srand(time(NULL));
    int tries = 0;
    while (!isSorted(arr))
    {
        shuffle(arr);
        tries++;
        cout << "Percobaan Ke-" << tries << ":";
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
}
// merge sort
void merge(vector<int> &arr, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
    {
        L[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++)
    {
        R[j] = arr[mid + 1 + j];
    }

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSortHelper(vector<int> &arr, int left, int right)
{
    if (left >= right)
    {
        return;
    }
    int mid = (left + right) / 2;
    mergeSortHelper(arr, left, mid);
    mergeSortHelper(arr, mid + 1, right);
    cout << "kiri : ";
    for (int i = left; i <= mid; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "|| ";
    cout << "kanan: ";
    for (int i = mid + 1; i <= right; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    merge(arr, left, mid, right);
    cout << "-------------------------------------" << endl;
    cout << "b : ";
    for (int i = left; i <= right; i++)
    {
        cout << "[" << arr[i] << "]"
             << " ";
    }
    cout << endl;
    cout << "+++++++++++++++++++++++++++++++++++++" << endl;
    cout << endl;
}

void mergeSort(vector<int> &arr)
{
    int n = arr.size();
    mergeSortHelper(arr, 0, n - 1);
}

// linear search
vector<int> LinearSearch(vector<int> &arr, int key)
{
    vector<int> ind;
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr.size(); j++)
        {
            if (arr[i] == key)
            {
                cout << " [" << arr[j] << "] ";
            }
            else
            {
                cout << " [" << arr[j] << "] ";
            }
        }
        cout << endl
             << "Apakah " << key << " = " << arr[i] << "? ";
        if (key == arr[i])
        {
            cout << "YA\n";
            ind.push_back(i);
        }
        else
        {
            cout << "TIDAK";
        }
        cout << endl
             << endl;
    }
    return ind;
}
//binary search
int binarySearch(vector<int> &  arr, int low, int high, int key)
{
    cout << "Array tempat pencarian akan dilakukan adalah:\n{";
    for (int i = 0; i < arr.size() ; i++) {
        cout << arr[i] << ", ";
    }
    cout << "}" << endl;

    while (low <= high) {
        cout << "\n 1. Pointer lownya adalah  :   " << low << "." ;
        cout << "\n 2. Pointer highnya adalah :   " << high << "." ;
        int mid = (low+high) / 2;
        cout << "\n 3. Pointer midnya yaitu arr[(" << low << " + " << high << ")/2] = arr[" << mid << "] = " << arr[mid] << ".\n" << endl;
        if (arr[mid] == key) {
            return mid;
        } else if (arr[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
        if (low > high) {
            cout << "\nHasil: Elemen " << key << " tidak ditemukan di dalam array.\n";
            return -1;
        }
        cout << " 4. Pointer rendah dinaikkan ke indeks " << low << " (setelah elemen " << arr[mid] << ") dan proses berlanjut dari langkah 3.\n";

    }
}



void printArray(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void longLine(int howLong)
{
    for (int i = 0; i < howLong; i++)
    {
        cout << "=";
    }
}

int main()
{
    // Get the input array from the user
    int banyak;
    int key;


    string nama, pil;
    longLine(40);
    cout << endl;
    cout << "   Program Sorting Dan Searching Data  " << endl;
    cout << "      By : Primavieri Rhesa Ardana     " << endl;
    longLine(40);
    cout << endl;
    cout << "Silahkan Masukkan Nama Panggilan Anda : " << endl;
    cin >> nama;
    cout << "----------------------------------------" << endl;
    cout << "Haloo " << nama << " Selamat Datang di Program Sorting" << endl;
    cout << endl;
    // Display the menu and get the user's choice
    while (true)
    {
        cout << "Pilihan Metode Sorting Dan Searching" << endl;
        cout << "A. Bubble Sort" << endl;
        cout << "B. Selection Sort" << endl;
        cout << "C. Insertion Sort" << endl;
        cout << "D. Merge Sort" << endl;
        cout << "E. Bogo Sort" << endl;
        cout << "F. Linier Searching" << endl;
        cout << "G. Binary Searching" << endl;
        cout << "H. Exit" << endl;
        cout << "Silahkan Pilih Operasi Yang Ingin Digunakan (A/B/C/D/E/F/G/H): ";
        cin >> pil;
        if (pil == "A" || pil == "B" || pil == "C" || pil == "D" || pil == "E" || pil == "F" || pil == "G")
        {
            cout << "Silahkan Masukkan Panjangnya Array : ";
            cin >> banyak;
            vector<int> arr(banyak);
            cout << "Silahkan Masukkan " << banyak <<" Element dari Array : ";
            for (int i = 0; i < banyak; i++)
            {
                cin >> arr[i];
            }
            cout << "\nArray Sebelum : ";
            for (int i = 0; i < banyak; i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl
                 << endl;
            if (pil == "A")
            {
                bubbleSort(arr);
                cout << "\nSetelah Sorting" << endl;
                printArray(arr);
                cout << endl;
            }
            else if (pil == "B")
            {
                selectionSort(arr);
                cout << "\nSetelah Sorting" << endl;
                printArray(arr);
                cout << endl;
            }
            else if (pil == "C")
            {
                insertionSort(arr);
                cout << "\nSetelah Sorting" << endl;
                printArray(arr);
                cout << endl;
            }
            else if (pil == "D")
            {
                mergeSort(arr);
                cout << "\nSetelah Sorting : " << endl;
                printArray(arr);
                cout << endl;
            }
            else if (pil == "E")
            {
                bogosort(arr);
                cout << "\nSetelah Sorting : " << endl;
                printArray(arr);
                cout << endl;
            }
            else if (pil == "F")
            {
                cout << "Masukkan Element Yang Ingin Dicari :";
                cin >> key;
                cout << endl;
                vector<int> ind = LinearSearch(arr, key);
                cout << endl
                     << endl
                     << "Maka " << key << " ditemukan pada index ke... ";
                for (int i = 0; i < ind.size(); i++)
                {
                    cout << ind[i] << " ";
                }
                cout << endl;
            }
            else if (pil == "G")
            {
                cout << "Masukkan Element Yang Ingin Dicari :";
                cin >> key;
                cout << endl;
                int result = binarySearch(arr, 0, banyak - 1, key);
                if (result == -1)
                cout << "Elemen tidak ditemukan di dalam array.";
                else
                cout << "Elemen " << key << " ditemukan pada indeks ke-" << result << ".\n\n";
            }
        }
        else if (pil == "H")
        {
            cout << "\nTerima Kasih Telah Menggunakan :>\n";
            break;
        }
        else
        {
            cout << "Operasi Tidak Valid :<, Silahkan Masukkan Ulang... " << endl;
        }
    }
    return 0;
}
