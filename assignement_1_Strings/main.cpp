#include <iostream>
#include <string>
#include <sstream>
#include <cstring>
#include <regex>
using namespace std;

/*MACROS PART*/
#define NUM_CATOGORY    4
#define NUM_EXTENSIONS   9

/*Enum for Extension Categories*/
typedef enum{
    Music = 0,
    Image,
    Movie,
    Others
}Files;

/*Function Prototypes*/
Files Check_Extension(string str);
string SizeDetector(string str);

int main(void)
{
    /*Initialization Variables*/
    uint32_t LOC_u32NumTestCases = 0;
    Files LOC_u8_Extension;
    uint32_t LOC_u32Iterator1 = 0, LOC_u32Iterator2 = 0;
    string LOC_TempStringName = "";
    string LOC_TempStringSize = "";
    uint32_t LOC_u32Size = 0;
    uint32_t Result[NUM_CATOGORY];
    uint32_t * LOC_u32PtrTestCases = NULL;

    /*SCAN NUMBER OF TEST CASES*/
    cin >> LOC_u32NumTestCases;
    
    /*DECLARE ARRAY WITH SIZE OF NUMBER OF TEST-CASES */
    LOC_u32PtrTestCases = new uint32_t[LOC_u32NumTestCases];
    /*LOOP TO SCAN EACH NUMBER OF INPUT OF EACH TEST CASES*/
    for (LOC_u32Iterator1 = 0; LOC_u32Iterator1 < LOC_u32NumTestCases; LOC_u32Iterator1++)
    {
        cin>>LOC_u32PtrTestCases[LOC_u32Iterator1];
    }
    /*LOOP TO RUN EACH TEST CASE*/
    for (LOC_u32Iterator1 = 0; LOC_u32Iterator1 < LOC_u32NumTestCases; LOC_u32Iterator1++)
    {
        /*RESET RESULT ARRAY*/
        memset(Result,0,sizeof(Result));
        /*LOOP TO TEST EACH INPUT IN TEST CASES*/
        for(LOC_u32Iterator2 = 0 ; LOC_u32Iterator2 <LOC_u32PtrTestCases[LOC_u32Iterator1] ; LOC_u32Iterator2++)
        {
            /*READ TOTAL LINE FROM CMD*/
            getline(cin >> ws, LOC_TempStringName);
            /*GET THE SIZE FROM THE END OF STRING*/
            LOC_TempStringSize=SizeDetector(LOC_TempStringName);
            /*REMOVE THE SIZE FROM THE STRING*/
            LOC_TempStringName.erase(LOC_TempStringName.find(" "+LOC_TempStringSize),LOC_TempStringSize.length()+1);
            /*STRING STREAM TO GET INT FROM STRING*/
            stringstream TempSS(LOC_TempStringSize.substr(0,LOC_TempStringSize.length()-1));
            TempSS>>LOC_u32Size;
            /*CALL FUNCTION TO CHECK EXTENSION FROM FILE NAME AND RETURN EXTENSION(ENUM)*/
            LOC_u8_Extension = Check_Extension(LOC_TempStringName);
            /*ACCESS ARRAY EXTENSION INDEX AND STORE DETECTED SIZE*/
            Result[LOC_u8_Extension]+=LOC_u32Size;
        }
        /*PRINT THE OUTPUT*/
    cout<<"music "<<Result[Music]<<"b "<<"images "<<Result[Image]<<"b "<<"movies "<<Result[Movie]<<"b "<<"other "<<Result[Others]<<"b"<<endl;
    }
    /*FREE RESERVED SPACE FROM HEAP*/
    delete(LOC_u32PtrTestCases);
    return 0;
}

/**
 * Extension Detector From String
 *
 * @param str Container of string represent file name.
 * @return Enum Extension of file name `Result`.
 */
Files Check_Extension(string str)
{
    /*VARIABLE WHOSE CONTAINING RETURNED EXTENSION*/
    Files Result = Others;
    /*CHECK BY REGEX IF THE 'str' ENDS WITH ONE OF MUSIC EXTENSIONS*/
    if(regex_match(str, regex("^.*(?=aac$|mp3$|flac$)[^.]+$")))
        Result = Music;
    /*CHECK BY REGEX IF THE 'str' ENDS WITH ONE OF IMAGE EXTENSIONS*/
    else if(regex_match(str, regex("^.*(?=jpg$|gif$|bmp$)[^.]+$")))
        Result = Image;
    /*CHECK BY REGEX IF THE 'str' ENDS WITH ONE OF MOVIE EXTENSIONS*/
    else if(regex_match(str, regex("^.*(?=mp4$|avi$|mkv$)[^.]+$")))
        Result = Movie;

    /*RETURN RESULT*/
    return Result;
    }

/**
 * Size Detector From String
 *
 * @param str Container of string represent file name with the file size in bytes.
 * @return String of file size `temp`.
 */
string SizeDetector(string str)
{
    /*INSTANCE OF STRINGSTREAM AND CALLING CONSTRUCTOR OF 1 PARAMETER*/
    stringstream ss(str);
    /*TEMP VARIABLE*/
    string temp = "";
    /*KEEP SPLITING THE STRING WITH WHITESPACES KEY UNTIL REACH TO THE LAST STRING*/
    while (ss>>temp);
    /*RETURN LAST STRING WHICH IS SIZE OF FILE*/
    return temp;
}