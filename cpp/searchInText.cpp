#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>

void naive(std::string pattern,std::string text)
{
    int m=pattern.size();
    int n=text.size();

    int j,i = 0;

    std::cout<<"indexes of instances the pattern into the text"<<std::endl;

    while(i<=n-m)
    {
        j=0;

        while(( j < m ) && ( pattern[j] == text[i+j] )) j++;
        if (j == m)
            std::cout<<i+1<<std::endl;
        i++;
    }

}

int PowerModuloFast(int a, int b, int m)
{
int i;
int result = 1;
long int x = a%m;

for (i=1; i<=b; i<<=1)
{
    x %= m;

    if ((b&i) != 0)
    {
        result *= x;
        result %= m;
    }

    x *= x;
}

return result%m;
}

void KR(std::string pattern, std::string text)
{
    const int r=256;
    const int q=9551;
    int m=pattern.size();
    int n=text.size();
    int h2=0,h1=0;

    std::cout<<"indexes of instances the pattern into the text"<<std::endl;


    for (int i=0; i<m; i++)
    {
        h2=((h2*r) + text[i]);
        h2%=q;
    }

    for (int i=0; i<m; i++)
    {
        h1=((h1*r) + pattern[i]);
        h1%=q;
    }

    int rm=PowerModuloFast(r, m-1, q);
    int i=0;

    while (i<n-m)
    {
        int j=0;
        if (h1==h2) while ((j<m)&&(pattern[j]==text[i+j])) j++;
        if (j==m) std::cout<<i+1<<std::endl;

        h2=((h2-text[i]*rm)*r+text[i+m]);
        h2%=q;

        if (h2<0) h2+=q;
        i++;
    }
    int j=0;
    if (h1==h2) while ((j<m)&&(pattern[j]==text[i+j])) j++;
    if (j==m) std::cout<<i+1<<std::endl;
}

void ComputePrefixFunction(std::string pattern,int pi[])
{
    int m=pattern.size();
    pi[0]=0;
    pi[1]=0;
    int k=0;
    for(int q=2; q<=m;q++)
    {
        while(k>0 && (pattern[k]!=pattern[q-1]))k=pi[k];
        if (pattern[k]==pattern[q-1])k++;
        pi[q]=k;
    }
}

int max(int value1, int value2) {return ( (value1 > value2) ? value1 : value2); }

void KMP(std::string pattern, std::string text)
{
    int n=text.size();
    int m=pattern.size();
    int pi[m];

    ComputePrefixFunction(pattern,pi);

    int q=0;
    std::cout<<"indexes of instances the pattern into the text"<<std::endl;
    int i=1,j=0;
    while (i<=n-m+1)
    {
        j=pi[j];
        while((j<m)&&(pattern[j]==text[i+j-1])) j++;
        if (j==m) std::cout<<i<<std::endl;
        i=i+max(1,j-pi[j]);
    }
}

void PreBadCharacterShift(std::string pattern,int badCharacterShift[])
{
    int m = pattern.size();
    for(int i = 0; i < 255 ; i++) badCharacterShift[i]=m;

    for (int i = 0; i < m - 1; i++) badCharacterShift[pattern[i]] = m - i - 1;
}

void PreSuff(std::string pattern , int suff[])
{   int i,j;
    int m = pattern.size();

    suff[m - 1] = m;

    for(i = m - 2 ; i >= 0 ; i--)
    {
        for(j = 0; j <= i && (pattern[i-j] == pattern[m-j-1]);j++) ;
        suff[i]=j;
    }
}

void PreGoodSuffixShift(std::string pattern, int suff[],int goodSuffixShift[])
{
    int m = pattern.size();

    PreSuff(pattern,suff);

    for(int i = 0 ; i < m ; i++) goodSuffixShift[i] = m;

    for (int i = m - 1; i >= 0; --i)
    {
        if (suff[i] == i + 1)
        {
            for (int j = 0; j < m - 1 - i; ++j)
            {
                goodSuffixShift[j] = m - 1 - i;
            }
        }
    }

    for (int i = 0; i <= m - 2; i++)
    {
         goodSuffixShift[m - 1 - suff[i]] = m - 1 - i;
    }


}
void BM(std::string pattern, std::string text)
{
    int m=pattern.size();
    int n=text.size();

    int badCharacterShift[255];
    int goodSuffixShift[m];
    int suff[n];

    PreBadCharacterShift(pattern,badCharacterShift);

    PreGoodSuffixShift(pattern,suff,goodSuffixShift);

    int j = 0;
    while (j <= n - m) {
    int i;
    for ( i = m - 1; i >= 0 && pattern[i] == text[i + j]; --i);
    if (i < 0) {
    std::cout<<j+1<<std::endl;
    j += goodSuffixShift[0];
    }
    else
    j += max(goodSuffixShift[i], badCharacterShift[text[i + j]] - m + 1 + i);
}
}

int main()
{
    std::string pattern,text;

    std::cout<<"type pattern"<<std::endl;
    std::getline(std::cin,pattern);
    std::cout<<"type text"<<std::endl;
    std::getline(std::cin, text);

    system("cls");

    std::cout<<"naive algorithm"<<std::endl;
    naive(pattern,text);
    std::cout<<std::endl;

    std::cout<<"Karp Rabin algorithm"<<std::endl;
    KR(pattern,text);
    std::cout<<""<<std::endl;

    std::cout<<"Knuth Morris Pratt algorithm"<<std::endl;
    KMP(pattern,text);
    std::cout<<""<<std::endl;

    std::cout<<"Boyer Moore algorithm"<<std::endl;
    BM(pattern,text);
    std::cout<<""<<std::endl;

    return 0;
}
