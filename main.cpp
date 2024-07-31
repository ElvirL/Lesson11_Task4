/*
Задание 4. Оценка результатов игры в крестики-нолики
Что нужно сделать
Петя и Вася играли в крестики-нолики и не стёрли результаты своей игры. Теперь перед вами табличка 3 ? 3, которая осталась после их 
поединка. Вы хотите понять, выиграл ли кто-то из них или они не доиграли.
На вход программе даётся три строки, кодирующие верхнюю, среднюю и нижнюю строчки игрового поля. 
Крестик обозначается символом X (английская заглавная буква X), нолик — символом O (заглавная английская буква O), 
пустая клетка — точкой.
Если ввод некорректен, то есть такая таблица не могла получиться в ходе настоящей игры, то надо написать в ответ слово Incorrect.
Если таблица корректна и выиграли крестики, то нужно вывести в ответ слова Petya won, если нолики — Vanya won, иначе 
(то есть они не доиграли или сыграли вничью) надо написать Nobody.
*/

#include <iostream>
#include <string>

using namespace std;

string read_table(){
    string answer = "";
    cout << "Введите три строки:" << endl;
    string line;
    for (int i=0; i<3; ++i){
        getline(cin, line);
        answer+=line;
    }
    return answer;
}


char get_elem_table(int x, int y, string table){
    return table[(3*x)+y];
}


char get_winner_row(string table){
    int counter_x = 0;
    int counter_o = 0;

    for (int i=0; i<3; ++i){
        for (int j=0; j<3; ++j){
            if (get_elem_table(i,j,table) == 'X')
                ++counter_x;
            else if (get_elem_table(i,j,table) == 'O')
                ++counter_o;
        }

        if (counter_x == 3)
            return 'X';
        else if (counter_o == 3)
            return 'O';

        counter_x = 0;
        counter_o = 0;
    }
    return '.';
}


char get_winner_column(string table){
    int counter_x = 0;
    int counter_o = 0;

    for (int i=0; i<3; ++i){
        for (int j=0; j<3; ++j){
            if (get_elem_table(j,i,table) == 'X')
                ++counter_x;
            else if (get_elem_table(j,i,table) == 'O')
                ++counter_o;
        }

        if (counter_x == 3)
            return 'X';
        else if (counter_o == 3)
            return 'O';

        counter_x = 0;
        counter_o = 0;
    }
    return '.';
}


char get_winner_main_diagonal(string table){
    int counter_x = 0;
    int counter_o = 0;

    for (int i=0; i<3; ++i){
        if (get_elem_table(i,i, table) == 'X')
            ++counter_x;
        else if (get_elem_table(i,i, table) == 'O')
            ++counter_o;
    }

    if (counter_x == 3)
            return 'X';
        else if (counter_o == 3)
            return 'O';

    return '.';    
}


char get_winner_another_diagonal(string table){
    int counter_x = 0;
    int counter_o = 0;

    for (int i=0; i<3; ++i){
        if (get_elem_table(i,2-i, table) == 'X')
            ++counter_x;
        else if (get_elem_table(i,2-i, table) == 'O')
            ++counter_o;
    }

    if (counter_x == 3)
            return 'X';
        else if (counter_o == 3)
            return 'O';

    return '.';    
}

string get_winner(string table){
    string answer = "";

    if (get_winner_row(table) == 'X' || get_winner_row(table) == 'O')
        answer+=get_winner_row(table);
    if (get_winner_column(table) == 'X' || get_winner_column(table) == 'O')
        answer+=get_winner_column(table);
    if (get_winner_main_diagonal(table) == 'X' || get_winner_main_diagonal(table) == 'O')
        answer+=get_winner_main_diagonal(table);
    if (get_winner_another_diagonal(table) == 'X' || get_winner_another_diagonal(table) == 'O')
        answer+=get_winner_another_diagonal(table);

    return answer;
}

bool is_correct_table(string table){
    for (size_t i=0; i< table.size(); ++i){
        if (table[i] != 'X' && table[i] !='O' && table[i] !='.'){
            return false;
        }
    }

    if (get_winner(table).size()>1)
        return false;
    
    int count_x = 0;
    int count_o = 0;

    for (size_t i=0; i<table.size(); ++i){
        if (table[i] == 'X')
            ++count_x;
        else if (table[i] == 'O')
            ++count_o;
    }

    if (count_o > count_x)
        return false;

    if (get_winner(table).front() == 'O' && count_x > count_o)
        return false;
    
    if (get_winner(table).front() == 'X' && count_o >=count_x)
        return false;
    
    
    return true;
}


int main(){
    setlocale(LC_ALL, "Russian");
    string table;
    table = read_table();

    if (!is_correct_table(table)){
        cout << "Incorrect " << endl;
    }
    else {
        if (get_winner(table).empty())
            cout << "Nobody" << endl;
        else if (get_winner(table).front() == 'X')
            cout << "Petya won" << endl;
        else if (get_winner(table).front() == 'O')
            cout << "Vanya won";
    }


}