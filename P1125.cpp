#include <iostream>
#include <string>
using namespace std;

bool isPrime(int num) {
    if(num <= 1) {  // 1不是素数
        return false;
    }
    for(int i = 2; i * i <= num; i++) {
        if(num % i == 0) {  // 如果num能被i整除，则不是素数
            return false;
        }
    }
    return true;
}

int main()
{
    string word;
    cin >> word;
    char currentLetter;
    char maxLetter;
    char minLetter;
    int currentCount = 0;
    int maxCount = 0;
    int minCount = 100;
    for (int i = 0; i < word.length(); i++)
    {
        currentLetter = word[i];
        for (int j = 0; j < word.length(); j++)
        {
            if (word[j] == currentLetter)
            {
                currentCount += 1;
            }
        }
        if (maxCount < currentCount)
        {
            maxCount = currentCount;
            maxLetter = currentLetter;
        }
        if (minCount > currentCount)
        {
            minCount = currentCount;
            minLetter = currentLetter;
        }
        currentCount = 0;
    }

    // cout<<maxCount<<endl<<minCount<<endl;

    if (isPrime(maxCount - minCount))
    {
        cout << "Lucky Word" << endl << maxCount - minCount << endl;
    }
    else
    {
        cout << "No Answer" << endl << 0 << endl;
    }
    
    return 0;
}