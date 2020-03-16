#include <iostream>
#include <fstream>
#include <string>
#include <ctype.h>

void Cipher(char , std::string, std::ofstream &);
bool BoolConvert(char, char, bool &);

int main(){
    std::string FileName;
    std::cout << "Txt file name (include .txt): " << std::endl;
    std::cin >> FileName;

    std::ifstream Ofile;
    Ofile.open(FileName);
    std::ofstream Cfile;
    char tmp;
    while(Ofile >> std::noskipws >> tmp){
        Cipher(tmp, FileName, Cfile);
    }
    Ofile.close();

}

void Cipher(char ch, std::string FileName, std::ofstream &Cfile){
    bool CaseUpper;
    char ABC[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    int Place;
    std::string CipherFileName = "C_" + FileName;
    Cfile.open(CipherFileName);
    for(int i = 0; i < 26; i++){
        //std::cout << i << std::endl;
        if(!std::isalpha(ch)){
            std::cout << i << std::endl;
            Cfile << ch;
            break;
        }
        if(BoolConvert(ch, ABC[i], CaseUpper)){
            //std::cout << i << std::endl;
            Place = i;
            int shift;
            shift = Place + 3;

            if(shift > 25){
                shift -= 26;
                char tmp = ABC[shift-1];
                std::cout << tmp << std::endl;
                Cfile << tmp;
                Cfile.close();
            }else{
                char tmp = ABC[shift];
                std::cout << tmp << std::endl;
                Cfile << tmp;
                Cfile.close();
            }
            break;
        }



    }
    Cfile.close();
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
