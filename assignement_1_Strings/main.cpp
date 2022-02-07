#include <iostream>
#include <string>
#include <sstream>
#include <cstring>
#include <regex>
using namespace std;

/*MACROS PART*/
#define NUM_CATOGORY    4
#define NUM_EXTENSIONS   9


typedef enum{
    Music = 0,
    Image,
    Movie,
    Others
}Files;

Files Check_Extension(string str);
string SizeDetector(string str);

int main(void)
{
    
    uint32_t LOC_u32NumTestCases = 0;
    Files LOC_u8_Extension;
    uint32_t LOC_u32Iterator1 = 0, LOC_u32Iterator2 = 0;
    string LOC_TempStringName = "";
    string LOC_TempStringSize = "";
    uint32_t LOC_u32Size = 0;
    uint32_t Result[NUM_CATOGORY];
    uint32_t * LOC_u32PtrTestCases = NULL;
    cin >> LOC_u32NumTestCases;
    LOC_u32PtrTestCases = new uint32_t[LOC_u32NumTestCases];
    for (LOC_u32Iterator1 = 0; LOC_u32Iterator1 < LOC_u32NumTestCases; LOC_u32Iterator1++)
    {
        cin>>LOC_u32PtrTestCases[LOC_u32Iterator1];
    }

    for (LOC_u32Iterator1 = 0; LOC_u32Iterator1 < LOC_u32NumTestCases; LOC_u32Iterator1++)
    {
        memset(Result,0,sizeof(Result));
        for(LOC_u32Iterator2 = 0 ; LOC_u32Iterator2 <LOC_u32PtrTestCases[LOC_u32Iterator1] ; LOC_u32Iterator2++)
        {
            getline(cin >> ws, LOC_TempStringName);
            LOC_TempStringSize=SizeDetector(LOC_TempStringName);
            LOC_TempStringName.erase(LOC_TempStringName.find(" "+LOC_TempStringSize),LOC_TempStringSize.length()+1);

            stringstream TempSS(LOC_TempStringSize.substr(0,LOC_TempStringSize.length()-1));
            TempSS>>LOC_u32Size;
            LOC_u8_Extension = Check_Extension(LOC_TempStringName);
            Result[LOC_u8_Extension]+=LOC_u32Size;
        }
    cout<<"music "<<Result[Music]<<"b "<<"images "<<Result[Image]<<"b "<<"movies "<<Result[Movie]<<"b "<<"other "<<Result[Others]<<"b"<<endl;
    }
}

//mysong.mp3.jpg   rfind
Files Check_Extension(string str)
{
    Files Result = Music;
    if(regex_match(str, regex("^.*(?=aac$|mp3$|flac$)[^.]+$")))
        Result = Music;
    else if(regex_match(str, regex("^.*(?=jpg$|gif$|bmp$)[^.]+$")))
        Result = Image;
    else if(regex_match(str, regex("^.*(?=mp4$|avi$|mkv$)[^.]+$")))
        Result = Movie;
    else
    {
        Result = Others;
    }
    // string LOC_StrExtenstions[9]={".mp3",".aac",".flac" ,".jpg",".gif",".bmp",".mp4",".avi",".mkv"};
    // uint8_t u8Index = 0;
    // uint8_t LOC_Iterator = 0;
    // //Song.aac.jpg.mp3
    // for(LOC_Iterator = 0 ; LOC_Iterator < NUM_EXTENSIONS ; LOC_Iterator++)
    // {
    //     if((LOC_Iterator>=0 && LOC_Iterator < 3) && (u8Index < str.rfind(LOC_StrExtenstions[LOC_Iterator]) &&  str.rfind(LOC_StrExtenstions[LOC_Iterator]) <100 ))
    //     {
    //         Result = Music;
    //         u8Index = str.rfind(LOC_StrExtenstions[LOC_Iterator]);
    //         // cout<<"MUSIC"<<endl;
    //     }
    //     if((LOC_Iterator>=3 && LOC_Iterator < 6) && (u8Index < str.rfind(LOC_StrExtenstions[LOC_Iterator]) &&  str.rfind(LOC_StrExtenstions[LOC_Iterator]) <100 ))
    //     {
    //         Result = Image;
    //         u8Index = str.rfind(LOC_StrExtenstions[LOC_Iterator]);
    //         // cout<<"IMAGE"<<endl;
    //     }
    //     if((LOC_Iterator>=6 && LOC_Iterator <= NUM_EXTENSIONS)  && (u8Index < str.rfind(LOC_StrExtenstions[LOC_Iterator]) &&  str.rfind(LOC_StrExtenstions[LOC_Iterator]) <100 ))
    //     {
    //         Result = Movie;
    //         u8Index = str.rfind(LOC_StrExtenstions[LOC_Iterator]);
    //         // cout<<"MOVIE"<<endl;
    //     }
    // }
    // if(u8Index < str.rfind(".") && str.rfind(".") < 100)
    // {
    //     Result = Others;
    //     // cout<<"OTHERS"<<endl;
    // }

    return Result;
    }

string SizeDetector(string str)
{
    stringstream ss(str);
    string temp = "";
    while (ss>>temp);
    return temp;
}