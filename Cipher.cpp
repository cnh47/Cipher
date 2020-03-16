#include <iostream>
#include <fstream>
#include <string>
#include <ctype.h>

char Cipher(char , std::string);
bool BoolConvert(char, char, bool &);

int main(){
    std::string FileName;
    std::cout << "Txt file name (include .txt): " << std::endl;
    std::cin >> FileName;

    std::ifstream Ofile;
    Ofile.open(FileName);

    std::ofstream Cfile;
    std::string CipherFileName = "C_" + FileName;
    Cfile.open(CipherFileName);

    char tmp;
    while(Ofile >> std::noskipws >> tmp){
        char filler;
        filler = Cipher(tmp, FileName);
        Cfile << filler;
    }
    Cfile.close();
    Ofile.close();

}

char Cipher(char ch, std::string FileName){
    bool CaseUpper;
    char ABC[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    int Place;
    for(int i = 0; i < 26; i++){
        if(!std::isalpha(ch)){
            return ch;
        }
        if(BoolConvert(ch, ABC[i], CaseUpper)){
            Place = i;
            int shift;
            shift = Place + 3;

            if(shift > 25){
                shift -= 26;
                char tmp = ABC[shift-1];
                return tmp;
            }else{
                char tmp = ABC[shift];
                return tmp;
            }
            break;
        }

    }
}

bool BoolConvert(char ch, char ABC, bool &CaseUpper){

    if(isupper(ch)){
        if(ch == ABC){
            CaseUpper = true;
            return true;
        }else{
            CaseUpper = true;
            return false;
        }
    }else{
        char UpperCh;
        UpperCh = toupper(ch);

        if(UpperCh == ABC){
            CaseUpper = false;
            return true;
        }else{
            CaseUpper = false;
            return false;
        }
    }
}
