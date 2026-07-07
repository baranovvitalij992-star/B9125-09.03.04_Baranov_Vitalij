#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main() {
    setlocale(LC_ALL, "RU");
    
    string money;
    cout << "Введите сумму: ";
    cin >> money;
    
    string string_whole_money = "";
    string string_hundredths_money = "";
    
    int dot_position = -1;
    int length_whole_numbers = 0;
    int length_hundredths_numbers = 0;
    
    for (int i = 0; i < money.length() && dot_position == -1; i++) {
        if (money[i] == '.') {
            dot_position = i;
        }
    }
    
    if (dot_position == -1) {
        string_whole_money = money;
        string_hundredths_money = "00";
    } else {
        length_whole_numbers = dot_position;
        for (int i = 0; i < dot_position; i++) {
            string_whole_money += money[i];
        }
        
        length_hundredths_numbers = money.length() - dot_position - 1;
        for (int i = dot_position + 1; i < money.length(); i++) {
            string_hundredths_money += money[i];
        }
        
        if (length_hundredths_numbers == 1) {
            string_hundredths_money += '0';
        }
    }
    
    int rubles = stoi(string_whole_money);
    int kopeiki = stoi(string_hundredths_money);
    
    if (kopeiki >= 100) {
        cout << "Ошибка: копеек не может быть больше 99" << endl;
        return 0;
    }
    
    string result = "";

    string units[] = {"", "один", "два", "три", "четыре", "пять", "шесть", "семь", "восемь", "девять"};
    string teens[] = {"десять", "одиннадцать", "двенадцать", "тринадцать", "четырнадцать", "пятнадцать", "шестнадцать", "семнадцать", "восемнадцать", "девятнадцать"};
    string tens[] = {"", "", "двадцать", "тридцать", "сорок", "пятьдесят", "шестьдесят", "семьдесят", "восемьдесят", "девяносто"};
    string hundreds[] = {"", "сто", "двести", "триста", "четыреста", "пятьсот", "шестьсот", "семьсот", "восемьсот", "девятьсот"};

    bool flag_rubles = false;
    bool flag_kopeiki = false;

    switch (rubles >= 0) {
        case true:
            switch (rubles == 0) {
                case true: 
                    result += "ноль ";
                    break;
            }
            
            switch (rubles >= 1000) {
                case true: {
                    int thousands = rubles / 1000;
                    
                    switch (thousands >= 100) {
                        case true:
                            result += hundreds[thousands / 100] + " ";
                            thousands %= 100;
                            break;
                    }
                    
                    switch (thousands >= 20) {
                        case true:
                            result += tens[thousands / 10] + " ";
                            thousands %= 10;
                            break;
                        case false:
                            switch (thousands >= 10) {
                                case true:
                                    result += teens[thousands - 10] + " тысяч ";
                                    thousands = 0;
                                    break;
                            }
                            break;
                    }
                    
                    switch (thousands > 0) {
                        case true:
                            switch (thousands) {
                                case 1: result += "одна тысяча "; break;
                                case 2: result += "две тысячи "; break;
                                case 3: result += "три тысячи "; break;
                                case 4: result += "четыре тысячи "; break;
                                default: result += units[thousands] + " тысяч ";
                            }
                            break;
                    }
                    rubles %= 1000;
                    break;
                }
            }

            switch (rubles >= 100) {
                case true:
                    result += hundreds[rubles / 100] + " ";
                    rubles %= 100;
                    break;
            }

            switch (rubles >= 20) {
                case true:
                    result += tens[rubles / 10] + " ";
                    rubles %= 10;
                    break;
                case false:
                    switch (rubles >= 10) {
                        case true:
                            result += teens[rubles - 10] + " ";
                            rubles = 0;
                            break;
                    }
                    break;
            }

            switch (rubles > 0) {
                case true:
                    switch (rubles) {
                        case 1: result += "один рубль "; flag_rubles = true; break;
                        case 2: result += "два рубля "; flag_rubles = true; break;
                        case 3: result += "три рубля "; flag_rubles = true; break;
                        case 4: result += "четыре рубля "; flag_rubles = true; break;
                        default: result += units[rubles] + " рублей "; flag_rubles = true;
                    }
                    break;
            }

            switch (!flag_rubles && rubles >= 0) {
                case true:
                    result += "рублей ";
                    break;
            }

            switch (kopeiki > 0) {
                case true:
                    switch (kopeiki >= 20) {
                        case true:
                            result += tens[kopeiki / 10] + " ";
                            kopeiki %= 10;
                            break;
                        case false:
                            switch (kopeiki >= 10) {
                                case true:
                                    result += teens[kopeiki - 10] + " ";
                                    kopeiki = 0;
                                    break;
                            }
                            break;
                    }
                    switch (kopeiki > 0) {
                        case true:
                            switch (kopeiki) {
                                case 1: result += "одна копейка"; flag_kopeiki = true; break;
                                case 2: result += "две копейки"; flag_kopeiki = true; break;
                                case 3: result += "три копейки"; flag_kopeiki = true; break;
                                case 4: result += "четыре копейки"; flag_kopeiki = true; break;
                                default: result += units[kopeiki] + " копеек"; flag_kopeiki = true;
                            }
                            break;
                    }
                    
                    switch (!flag_kopeiki) {
                        case true: 
                            result += "копеек";
                            break;
                    }
                    break;
                case false: 
                    result += "ноль копеек";
                    break;
            }
            break;
        case false:
            cout << "Сумма не может быть отрицательной" << endl;
            break;
    }

    cout << "Результат: " << result << endl;

    return 0;
}