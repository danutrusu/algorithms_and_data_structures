#include <iostream>
#include <map>
#include <vector>
using namespace std;

string* printStrings(int length, string *arr);
string* readStrings(int length);

void quickSort(char *arr, int left, int right)
{
    int i = left, j = right;
    char pivot = arr[ (left + right) / 2];
    while (i < j) {
        while (arr[i] < pivot) {
            i++;
        }
        while(arr[j] > pivot) {
            j--;
        }
        if(i<=j) {
            swap(arr[i++],arr[j--]);
        }
    }
    if (i < right) {
        quickSort(arr,i, right);
    }

    if (j > left) {
        quickSort(arr,left, j);
    }
}

void sortAnagrams(string *arr, int length) {
    map<string,vector<string>> sortedAnagrams;
    map<string,vector<string>>::iterator it;

    for (int i = 0;i < length; ++i) {
        char *s;
        s = new char[arr[i].length()];
        arr[i].copy(s,arr[i].length());
        quickSort(s, 0, arr[i].length() - 1);
        sortedAnagrams[s].push_back(arr[i]);
    }

    it = sortedAnagrams.begin();
    for(; it != sortedAnagrams.end(); ++it) {
        vector<string> vecStrings = it->second;
        for(int i = 0; i < vecStrings.size(); ++i )
            cout << vecStrings[i]<< " ";
        cout<<'\n';
    }
}

int main() {
    string *arr;
    int length;
    cin >> length;
    arr = readStrings(length);
    sortAnagrams(arr,length);

    return 0;
}

string* readStrings(int length)
{
    string *arr = new string[length];
    for(int i = 0; i < length; ++i) {
        cin >> arr [i];
    }

    return arr;
}


string* printStrings(int length, string *arr)
{
    for(int i = 0;i < length; ++i) {
        cout<<arr[i]<<" ";
    }
}
