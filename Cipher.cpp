#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
#include <ctype.h>

void CreateFile(std::string);
void KeyRipper(int, int &, int &);
void Sequence(int &, int &, int &);
char CipherText(char, int, int);
char DecipherText(char, int, int);
bool BoolConvert(char, char, bool &);
void Cipher(int, int);
void Decipher(int, int);

int main(){
    while(true){
        int User, shifter, rep, SR, Key;
        char YN;
        srand(time(0));
        std::cout << "(1) Cipher" << std::endl;
        std::cout << "(2) Decipher" << std::endl;
        std::cin >> User;

        std::cout << "Do you have a key? (y/n): " << std::endl;
        std::cin >> YN;
        if(YN == 'y' || YN == 'Y'){
            std::cout << "Enter Key: " << std::endl;
            std::cin >> Key;
            KeyRipper(Key, shifter, rep);
            if(User == 1){
                Cipher(rep, shifter);
                std::cout << "Cipher Complete" << std::endl;
                break;
            }else if(User == 2){

                Decipher(rep, shifter);
                std::cout << "Decipher Complete" << std::endl;
                break;
            }else{
                std::cout << "Enter a valid number" << std::endl;
            }
        }else if(YN == 'n' || YN == 'N'){
            Sequence(shifter, rep, SR);

            if(User == 1){
                Cipher(rep, shifter);
                std::cout << "Cipher Complete" << std::endl;
                break;
            }else if(User == 2){

                Decipher(rep, shifter);
                std::cout << "Decipher Complete" << std::endl;
                break;
            }else{
                std::cout << "Enter a valid number" << std::endl;
            }
        }else{
            std::cout << "Enter Either Y or N" << std::endl;
        }
    }

}


void CreateFile(std::string FileName){
    std::ofstream CreateFile;
    CreateFile.open(FileName);
    CreateFile.close();
}

void KeyRipper(int Key, int &shifter, int &rep){
    int Lng;
    std::string KeyTmp;
    std::string tmp = std::to_string(Key);
    Lng = tmp.length();
    shifter = stoi(tmp.substr(0,2));
    rep = stoi(tmp.substr(2,Lng));
}

void Sequence(int &shifter, int &rep, int &SR){
    std::string a, b, tmp;

    rep = rand() % 9999 + 1000;
    shifter = rand() % 25 + 1;

    a = std::to_string(shifter);
    b = std::to_string(rep);
    tmp = a + b;
    SR = stoi(tmp);
}

void Cipher(int rep, int shifter){
    std::string FileName;
    std::cout << "Txt file name (include .txt): " << std::endl;
    std::cin >> FileName;

    std::ifstream Ofile;
    Ofile.open(FileName);
    std::ofstream Cfile;

    std::string CipherFileName = "C" + FileName;

    //CreateFile(CipherFileName);
    Cfile.open(CipherFileName);

    char tmp;
    while(Ofile >> std::noskipws >> tmp){
        char filler;
        filler = CipherText(tmp, rep, shifter);
        Cfile << filler;
    }

    Cfile.close();
    Ofile.close();
}

void Decipher(int rep, int shifter){
    std::string FileName;
    std::cout << "Txt file name (include .txt): " << std::endl;
    std::cin >> FileName;

    std::ifstream Ofile;
    Ofile.open(FileName);

    std::ofstream Cfile;
    std::string DecipherFileName = "D" + FileName;
    Cfile.open(DecipherFileName);

    char tmp;
    while(Ofile >> std::noskipws >> tmp){
        char filler;
        filler = DecipherText(tmp, rep, shifter);
        Cfile << filler;
    }

    Cfile.close();
    Ofile.close();
}

char CipherText(char ch, int rep, int shifter){
    int loop = rep;
    for(int j = 0; j < loop; ++j){
        bool CaseUpper;
        char ABC[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
        int Place;
        for(int i = 0; i < 26; i++){

            if(BoolConvert(ch, ABC[i], CaseUpper)){
                Place = i;
                int shift;
                shift = Place + shifter;

                if(CaseUpper == false){
                    if(shift > 25){
                        shift -= 26;
                        ch = tolower(ABC[shift]);
                        if(j == loop - 1)
                            return ch;
                    }else{
                        ch = tolower(ABC[shift]);
                        if(j == loop - 1)
                            return ch;
                    }
                }else{
                    if(shift > 25){
                        shift -= 26;
                        ch = ABC[shift];
                        if(j == loop - 1)
                            return ch;
                    }else{
                        ch = ABC[shift];
                        if(j == loop - 1)
                            return ch;
                    }
                }
                break;
            }else if(!std::isalpha(ch)){
                return ch;
            }

        }
    }
}

char DecipherText(char ch, int rep, int shifter){
    int loop = rep;
    for(int j = 0; j < 1000; ++j){
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
                shift = Place - shifter;

                if(CaseUpper == false){
                    if(shift < 0){
                        shift += 26;
                        ch = tolower(ABC[shift]);
                        if(j == loop - 1)
                            return ch;
                    }else{
                        ch = tolower(ABC[shift]);
                        if(j == loop - 1)
                            return ch;
                    }
                }else{
                    if(shift < 0){
                        shift += 26;
                        ch = ABC[shift];
                        if(j == loop - 1)
                            return ch;
                    }else{
                        ch = ABC[shift];
                        if(j == loop - 1)
                            return ch;
                    }
                }
                break;
            }

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
