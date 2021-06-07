#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <cctype>
#include <stdlib.h>
#include <cstdio>
#include <stack>

using namespace std;
using namespace std::chrono;

struct Profile
{
    string full_name;
    string sex;
    int group;
    int id;
    int grades[8];
    char depart[9];
    string date;
};

//Данные о студентах с id i
void show(vector<Profile> student, int n, int i)
{
    cout << "Full name: " << student[i].full_name << "\n";
    cout << "Group: " << student[i].group << "\n";
    cout << "Index: " << student[i].id << "\n";
    cout << "Sex (F/M): " << student[i].sex << "\n";
    cout << "Department (day/evening/distance): " << student[i].depart << "\n";
    cout << "Term grades: ";
    for (int j = 0; j < 8; j++) cout << student[i].grades[j] << " ";  cout << "\n";
    cout << "Date and time of recording:" << student[i].date << "\n\n";
}

//Вывод всех данных о студентах
void showStud(vector<Profile> student, int n)
{
    int stud;
    cout << "All students on the list\n\n";
    for (int i = 0; i < n; i++)
    {
        stud = i + 1;
        cout << "Student " << stud << "\n\n";
        cout << "Full name: " << student[i].full_name << "\n";
        cout << "Group: " << student[i].group << "\n";
        cout << "Index: " << student[i].id << "\n";
        cout << "Sex (F/M): " << student[i].sex << "\n";
        cout << "Department (day/evening/distance): " << student[i].depart << "\n";
        cout << "Term grades: ";
        for (int j = 0; j < 8; j++) cout << student[i].grades[j] << " ";  cout << "\n";
        cout << "Date and time of recording:" << student[i].date << "\n\n";
    }
    cout << "\n\n";
    system("pause");
    system("cls");
}
//Создание новой записи о студенте
void add(vector<Profile>& student, int& n)
{
    n++;
    student.resize(n);
    int i = n - 1;

    ofstream  fi;
    fi.open("students.txt", fstream::app);
    if (!fi.is_open())
    {
        cout << "\nFile opening error";
    }
    else {
        cout << "Enter full name: ";
        cin.ignore();
        getline(cin, student[i].full_name);
        fi << student[i].full_name << "\n";

        cout << "Enter group: ";
        cin >> student[i].group;
        fi << student[i].group << "\n";

        cout << "Enter the id: ";
        cin >> student[i].id;
        fi << student[i].id << "\n";

        cout << "Enter the gender of the person(F/M): ";
        cin.ignore();
        getline(cin, student[i].sex);
        fi << student[i].sex << "\n";

        cout << "Enter the form of study(day/evening/distance): ";
        cin >> student[i].depart;
        fi << student[i].depart << "\n";

        for (int j = 0; j < 8; j++) { cout << "Enter grades: "; cin >> student[i].grades[j]; }
        for (int j = 0; j < 8; j++) fi << student[i].grades[j] << " ";
        fi << "\n";

        cout << "Enter the date and time of the recording: ";
        cin.ignore();
        getline(cin, student[i].date);
        fi << student[i].date << "\n";
    }

    fi.close();
    cout << "\n\nRecorded\n\n";
    system("pause");
    system("cls");
}
//Запись нового студента в файл
void recording(vector<Profile>& student, int& n)
{
    ofstream Rec;
    Rec.open("students.txt");
    if (!Rec.is_open())
    {
        cout << "\nFile opening error";
    }
    else {

        for (int i = 0; i < n; i++)
        {
            Rec << student[i].full_name << "\n";
            Rec << student[i].group << "\n";
            Rec << student[i].id << "\n";
            Rec << student[i].sex << "\n";
            Rec << student[i].depart << "\n";
            for (int j = 0; j < 8; j++) Rec << student[i].grades[j] << " ";
            Rec << "\n";
            Rec << student[i].date << "\n";
        }
    }
    Rec.close();
}
//Внесение изменений в уже имеющуюся запись
void change(vector<Profile>& student, int& n)
{
    int num, choose;
    cout << "Enter student number from 1 to " << n << "\n";
    cout << "You entered: ";
    cin >> num;
    num--;

    cout << "\nWhat needs to be changed\n\n";
    cout << "1 - full name\n";
    cout << "2 - group number\n";
    cout << "3 - id\n";
    cout << "4 - sex\n";
    cout << "5 - department (day/evening/distance)\n";
    cout << "6 - grades\n";
    cout << "7 - date and time of the recording\n";

    cout << "\nYou entered: ";
    cin >> choose;
    cout << "\n";

    switch (choose)
    {
    case 1:
        cout << "Enter full name: "; cin.ignore();
        getline(cin, student[num].full_name);
        break;
    case 2:
        cout << "Enter group: ";
        cin >> student[num].group;
        break;
    case 3:
        cout << "Enter the id: ";
        cin >> student[num].id;
        break;
    case 4:
        cout << "Enter the gender of the person(F/M): "; cin.ignore();
        getline(cin, student[num].sex);
        break;
    case 5:
        cout << "Enter the form of study(day/evening/distance): "; cin.ignore();
        cin >> student[num].depart;
        break;
    case 6:
        for (int j = 0; j < 8; j++) { cout << "Enter grades: "; cin >> student[num].grades[j]; }
        break;
    case 7:
        cout << "Enter the date and time of the recording: "; cin.ignore();
        getline(cin, student[num].date);
        break;
    }
    recording(student, n);
    cout << "\nData changed\n\n";
    system("pause");
    system("cls");
}
//Вывод информации обо всех студентах группы N
void showGroup(vector<Profile> student, int n)
{
    int num, check = 0;
    cout << "Enter group number";
    cout << "\nYou entered: ";
    cin >> num; cout << "\n";
    for (int i = 0; i < n; i++)
    {
        if (student[i].group == num)
        {
            show(student, n, i);
            check = 1;
        }
    }

    if (check == 0) cout << "There is no such group";
    cout << "\n\n";
    system("pause");
    system("cls");
}
//Вывод топа самых успешных студентов с наивысшим по рейтингу средним баллом за прошедшую сессию 
void rating(vector<Profile> student, int n)
{
    double* rating = new double[n];
    double max1 = 0, max2 = 0, max3 = 0, dub = 0.0;
    int top1 = 0, top2 = 0, top3 = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 8; j++)dub += student[i].grades[j];
        dub /= 8;

        rating[i] = dub;

        dub = 0;
    }
    for (int i = 0; i < n; i++) { if (rating[i] > max1) { max1 = rating[i]; top1 = i; } }
    for (int i = 0; i < n; i++) { if (rating[i] > max2 && student[i].full_name != student[top1].full_name) { max2 = rating[i]; top2 = i; } }
    for (int i = 0; i < n; i++) { if (rating[i] > max3 && student[i].full_name != student[top1].full_name && student[i].full_name != student[top2].full_name) { max3 = rating[i]; top3 = i; } }

    cout << "Top 1 with an average score: " << max1 << "\n\n";  show(student, n, top1);
    cout << "\n\nTop 2 with an average score: " << max2 << "\n\n";  show(student, n, top2);
    cout << "\n\nTop 3 with an average score: " << max3 << "\n\n";  show(student, n, top3);

    delete[] rating;
    cout << "\n\n";
    system("pause");
    system("cls");
}
//Вывод количества студентов мужского и женского пола
void gender(vector<Profile> student, int n)
{
    int countM = 0, countF = 0;
    for (int i = 0; i < n; i++)
    {
        if (student[i].sex == "F") countF++;
        if (student[i].sex == "M") countM++;
    }

    cout << "\n\nWomen: " << countF << "\n\n";
    cout << "Men: " << countM;

    cout << "\n\n\n";
    system("pause");
    system("cls");
}
//Определение количества студентов, которые будут получать стипендию 
void scholarship(vector<Profile> student, int n)
{
    int check = 0, count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 8; j++) {
            if ((student[i].grades[j] == 3) || (student[i].grades[j] == 2)) check = 1;
        }
        string a = student[i].depart;
        if (a == "day" && check == 0) count++;

        check = 0;
    }

    cout << "\n\nNumber of students with a scholarship: " << count << "\n\n\n";
    system("pause");
    system("cls");
}
//Вывод данных о студентах, которые не получают стипендию; учатся только на «хорошо» и «отлично»; учатся только на «отлично»
void noScholarship(vector<Profile> student, int n)
{
    int check = 0, count = 0, count5 = 0, count5_ = 0, count4 = 0;
    cout << "Students who do not receive a scholarship:\n\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 8; j++)
            if (student[i].grades[j] == 3 || student[i].grades[j] == 2) check = 1;
        string a = student[i].depart;
        if (a == "evening" || check == 1)
        {
            show(student, n, i);
        }

        check = 0;
    }
    system("pause"); system("cls");
    cout << "Students with grades 5 and 4:\n\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (student[i].grades[j] == 2) check = 1;
            if (student[i].grades[j] == 3) check = 1;
            if (student[i].grades[j] == 5) count5_++;
            if (student[i].grades[j] == 4) count4++;
        }
        if (check == 0 && count5_ < 8 && count4 > 0)
        {
            show(student, n, i);
        }
        count5_ = 0;
        check = 0;
    }
    system("pause"); system("cls");
    cout << "Excellent students:\n\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 8; j++)
            if (student[i].grades[j] == 5) count5++;

        if (count5 == 8)
        {
            show(student, n, i);
        }
        count5 = 0;
    }
    cout << "\n\n";
    system("pause");
    system("cls");
}
//Вывод данных о студентах, имеющих номер в списке
void showID(vector<Profile> student, int n)
{
    int num, check = 0;
    cout << "Enter student's id\n";
    cout << "You entered:";
    cin >> num; cout << "\n";
    for (int i = 0; i < n; i++)
    {
        if (student[i].id == num)
        {
            show(student, n, i);
            check = 1;
        }
    }

    if (check == 0) cout << "There is no such id";
    cout << "\n\n";
    system("pause");
    system("cls");
}
//Вывод всех записей, сделанных в день, который введет пользователь
void time(vector<Profile> student, int n)
{
    string t[12] = { "12","13","14","15","16","17","18","19","20","21","22","23" };
    string t_[12] = { "00","01","02","03","04","05","06","07","08","09","10","11" };
    string sub, dub, time_; int p, check = 0;
    cout << "Enter day of week,month and day as in the file: ";
    cin.ignore();
    getline(cin, time_); cout << "\n\n";
    for (int i = 0; i < n; i++)
    {
        sub = student[i].date;
        if (sub.find_first_not_of(time_) >= 10)
        {
            show(student, n, i);
            check = 1;
        }
    }
    if (check == 0) cout << "No notes made on this day\n\n";
    system("pause"); system("cls");
    cout << "Afternoon notes\n\n";
    for (int i = 0; i < n; i++)
    {
        dub = student[i].date;
        if (dub.size() == 24) p = 11;
        else p = 10;

        for (int j = 0; j < 12; j++)
        {
            if (t[j] == dub.substr(p, 2))
            {
                show(student, n, i);
            }
        }
    }
    system("pause"); system("cls");
    cout << "Notes made before noon\n\n";
    for (int i = 0; i < n; i++)
    {
        dub = student[i].date;
        if (dub.size() >= 24) p = 11;
        else p = 10;

        for (int j = 0; j < 12; j++)
        {
            if (t_[j] == dub.substr(p, 2))
            {
                show(student, n, i);
            }
        }
    }
    cout << "\n\n";
    system("pause");
    system("cls");
}

void PW1() {

    ifstream fin;
    fin.open("students.txt");
    int n = 0, task, task2, task3;
    while (!fin.eof()) {
        if (fin.get() == '\n')
            n++;
    }
    n = n / 7;
    fin.close();
    cout << "Number of students on the list: " << n << "\n\n";

    vector<Profile>student(n);

    ifstream f;
    f.open("students.txt");
    if (!f.is_open())
    {
        cout << "\nFile opening error";
    }
    else {
        for (int i = 0; i < n; i++)
        {
            getline(f, student[i].full_name);
            f >> student[i].group; f.ignore();
            f >> student[i].id; f.ignore();
            getline(f, student[i].sex);
            f >> student[i].depart; f.ignore();
            for (int j = 0; j < 8; j++) { f >> student[i].grades[j]; }
            f.ignore(2);
            getline(f, student[i].date);

        }
    }
    f.close();

    do
    {
        cout << "Enter number of task\n\n";
        cout << "1. Create a new student record\n";
        cout << "2. Making changes to an existing record\n";
        cout << "3. Display of all student data\n";
        cout << "4. Display of information about all students of group N\n";
        cout << "5. Finding the most successful students\n";
        cout << "6. Display of the number of male and female students\n";
        cout << "7. Determining the number of students who will receive the scholarship\n";
        cout << "8. Conclusion of data on students who: do not receive a scholarship, study only for good and excellent, study only excellently\n";
        cout << "9. Displays data about students who have a number in the list - k\n";
        cout << "10. Displays all entries made on the day that the user enters, displays all entries made in the afternoon, displays all entries made before noon.\n";
        cout << "To exit, enter 0\n";
        cout << "\n";

        cout << "You entered: ";
        cin >> task;

        system("cls");

        switch (task)
        {
        case 1:
            add(student, n);
            break;

        case 2:
            change(student, n);
            break;

        case 3:
            showStud(student, n);
            break;

        case 4:
            showGroup(student, n);
            break;

        case 5:
            rating(student, n);
            break;

        case 6:
            gender(student, n);
            break;

        case 7:
            scholarship(student, n);
            break;

        case 8:
            noScholarship(student, n);
            break;

        case 9:
            showID(student, n);
            break;

        case 10:
            time(student, n);
            break;

        case 0:
            break;
        }

    } while (task != 0);

}

struct list
{
    int data;
    list* prev;
    list* next;
};

int count_ = 0;
list* head = NULL, * tail = NULL;

//поиск индекса элемента num
int SerchInd_l(int num)
{
    list* t = head;
    int serch_c = 0;
    while (t) {

        if (t->data == num)
        {
            return serch_c;
            break;
        }
        t = t->next;
        serch_c++;
    }
}
//поиск элемента с индексом num
list* SerchData_l(int num)
{
    list* t = head;
    int serch_c = 0;
    while (t) {

        if (serch_c == num)
        {
            return t;
            break;
        }
        t = t->next;
        serch_c++;
    }
}

int SerchData_l3(int num)
{
    list* t = head;
    int serch_c = 0;
    while (t) {

        if (serch_c == num)
        {
            return t->data;
            break;
        }
        t = t->next;
        serch_c++;
    }
}
//заполнение списка
void Add_list(int x) {
    list* temp = new list;
    temp->data = x;
    temp->next = NULL;
    count_++;
    if (!head) {
        temp->prev = NULL;
        head = temp;
        tail = head;
    }
    else {
        temp->prev = tail;
        tail->next = temp;
        tail = temp;
    }
}
//вставка элемента не в начало списка
void Add_In(list* elem, int num)
{
    list* NewEl = new list;

    NewEl->data = num;
    if (elem->next == NULL) NewEl->next = NULL;
    else  NewEl->next = elem->next;
    elem->next = NewEl;
    NewEl->prev = elem;

    if (elem->next != NULL) elem->next->prev = NewEl;
    if (NewEl->next == NULL) tail = NewEl;
}
//вставка элемента в начало списка
void First_In(int num)
{
    list* NewEl = new list;
    list* tmp = head;
    NewEl->prev = NULL;
    NewEl->next = head;
    NewEl->data = num;

    tmp->prev = NewEl;
    tmp->next = head->next;

    head = NewEl;
}
//вставка элемента
void Insert_list(int in, int ch)
{
    count_++;
    int ind, num = ch, c = 0;
    ind = in;
    list* per = head;

    while (per != NULL)
    {
        if (ind == 0)
        {
            First_In(num);
            break;
        }
        if (c == ind - 1)
        {
            Add_In(per, num);
            break;
        }
        per = per->next; c++;
    }
}
//вывод списка
void Show_list() {
    list* t = head;
    while (t) {
        cout << t->data << " ";
        t = t->next;
    }
    cout << "\n\n";
}
//удаление элемента по индексу
void Del_list(int x)
{
    if ((x == 0) and (head->next)) {
        list* temp = head;
        head = head->next;
        head->prev = NULL;
        delete temp;
        count_--;
        return;
    }
    else if ((x == 0) and (head == tail)) {

        head->next = NULL;
        head = NULL;
        delete head;
        count_ = 0;
        return;
    }

    if (x == count_ - 1) {
        list* temp = tail;
        tail = tail->prev;
        tail->next = NULL;
        delete temp;
        count_--;
        return;
    }

    list* temp = SerchData_l(x);

    list* prev_el, * next_el;

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;

    delete temp;
    count_--;
}
//заполнение списка 1 способом
void Fill_list1(int N)
{
    int elem;
    for (int i = 0; i < N; i++)
    {
        elem = rand() % 199 - 99;
        Add_list(elem);
    }
}
//заполнение списка 2 способом
void Fill_list3()
{
    ifstream f;
    f.open("file.txt");
    if (!f.is_open())
    {
        cout << "\nFile opening error";
    }
    else {
        int i = 0, x;
        while (!f.eof())
        {
            f >> x;
            Add_list(x);
            i++;
        }
    }
    f.close();
}
//заполнение списка 3 способом
void Fill_list2()
{
    int tmp = 0;

    while (tmp != -1)
    {
        cin >> tmp;
        if (tmp == -1)return;
        Add_list(tmp);
    }
    system("cls");
}

//вывод массива
void Show_mas(int const* mas_dyn, int const& dyn)
{
    for (int i = 0; i < dyn; i++)
    {
        cout << mas_dyn[i] << " ";
    }
}
//заполнение массива 1 способом
void Fill_mas1(int& dyn_a, int* mas_dyn)
{
    for (int i = 0; i < dyn_a; i++)
    {
        mas_dyn[i] = rand() % 199 - 99;
    }
}
//заполнение массива 2 способом
void Fill_mas2(int& dyn_b, int* mas_dyn)
{
    int tmp = 0;
    while (tmp != -1)
    {
        cin >> tmp;
        if (tmp == -1)return;
        mas_dyn[dyn_b] = tmp;
        dyn_b++;
    }
    system("cls");
}
//заполнение массива 3 способом
void Fill_mas3(int& dyn_c, int* mas_dyn)
{
    ifstream f;
    f.open("file.txt");
    if (!f.is_open())
    {
        cout << "\nFile opening error";
    }
    else {
        int i = 0;
        while (!f.eof())
        {
            f >> mas_dyn[i];
            i++;
        }
        dyn_c = i;
    }
    f.close();
}
//расширение массива на 1
void Resize_P(int& N, int*& mas_dyn)
{
    int N2; N2 = N + 1;
    int* mas_rez = new int[N2];

    for (int i = 0; i < N2; i++)
        mas_rez[i] = mas_dyn[i];

    delete[] mas_dyn;

    mas_dyn = mas_rez;
}

//уменьшение массива на 1
void Resize_M(int& N, int*& mas_dyn)
{
    int N2; N2 = N - 1;
    int* mas_rez = new int[N2];

    for (int i = 0; i < N2; i++)
        mas_rez[i] = mas_dyn[i];

    delete[] mas_dyn;

    mas_dyn = mas_rez;
    N = N2;
}

//вставка элемента в массив
void Insert_mas(int& N, int*& mas_dyn, int ind, int ch)
{
    int newi = ind; int i_num = ch;
    Resize_P(N, mas_dyn);

    for (int i = N - 1; i >= newi; i--)
        mas_dyn[i + 1] = mas_dyn[i];

    mas_dyn[newi] = i_num;
    N++;
}

//удаление элемента по индексу
void Del_mas(int& N, int*& mas_dyn, int del)
{

    for (int i = del; i < N - 1; i++)
        mas_dyn[i] = mas_dyn[i + 1];

    Resize_M(N, mas_dyn);
}

//поиск индекса ind элемента ch
int SerchInd_m(int N, int* dyn_mas, int ch)
{
    for (int i = 0; i < N; i++)
    {
        if (dyn_mas[i] == ch) return i;
    }
}

//поиск элемента с индексом ind
int SerchData_m(int N, int* dyn_mas, int ind)
{
    for (int i = 0; i < N; i++)
    {
        if (i == ind) return dyn_mas[i];
    }
}

void Task_fill_time1(int*& mas_dyn, int& N)
{
    auto begin_m = steady_clock::now();
    Fill_mas1(N, mas_dyn);
    auto end_m = steady_clock::now();
    auto elepsed_m = duration_cast<nanoseconds>(end_m - begin_m);
    Show_mas(mas_dyn, N);
    cout << "\n\nTime spent in nanoseconds: " << elepsed_m.count() << "\n\n\n";

    auto begin_l = steady_clock::now();
    Fill_list1(N);
    auto end_l = steady_clock::now();
    auto elepsed_l = duration_cast<nanoseconds>(end_l - begin_l);
    Show_list();
    cout << "Time spent in nanoseconds: " << elepsed_l.count() << "\n";
}

void Task_fill_time2(int*& mas_dyn, int& N)
{
    auto fillmasB = steady_clock::now();
    Fill_mas2(N, mas_dyn);
    auto fillmasE = steady_clock::now();
    auto elepsed_mas = duration_cast<nanoseconds>(fillmasE - fillmasB);
    Show_mas(mas_dyn, N);
    cout << "\n\nTime spent in nanoseconds: " << elepsed_mas.count() << "\n\n\n";

    auto filllistB = steady_clock::now();
    Fill_list2();
    auto filllistE = steady_clock::now();
    auto elepsed_list = duration_cast<nanoseconds>(filllistE - filllistB);
    Show_list();
    cout << "Time spent in nanoseconds: " << elepsed_list.count() << "\n";
}

void Task_fill_time3(int*& mas_dyn, int& N)
{
    auto begin_m = steady_clock::now();
    Fill_mas3(N, mas_dyn);
    auto end_m = steady_clock::now();
    auto elepsed_m = duration_cast<nanoseconds>(end_m - begin_m);
    Show_mas(mas_dyn, N);
    cout << "\n\nTime spent in nanoseconds: " << elepsed_m.count() << "\n\n\n";

    auto begin_l = steady_clock::now();
    Fill_list3();
    auto end_l = steady_clock::now();
    auto elepsed_l = duration_cast<nanoseconds>(end_l - begin_l);
    Show_list();
    cout << "Time spent in nanoseconds: " << elepsed_l.count() << "\n";
}

void Task_insert_time(int*& mas_dyn, int& N)
{
    int ind, ch;
    cout << "Array\n"; Show_mas(mas_dyn, N);
    cout << "\n\nEnter index to insert: "; cin >> ind;
    cout << "Enter new element: "; cin >> ch;
    auto begin_m = steady_clock::now();
    Insert_mas(N, mas_dyn, ind, ch);
    auto end_m = steady_clock::now();
    auto elepsed_m = duration_cast<nanoseconds>(end_m - begin_m);
    cout << "\nArray after insertion\n"; Show_mas(mas_dyn, N);
    cout << "\n\nTime spent in nanoseconds: " << elepsed_m.count() << "\n\n\n";

    cout << "List\n"; Show_list();
    cout << "Enter index to insert: "; cin >> ind;
    cout << "Enter new element: "; cin >> ch; cout << "\n";
    auto begin_l = steady_clock::now();
    Insert_list(ind, ch);
    auto end_l = steady_clock::now();
    auto elepsed_l = duration_cast<nanoseconds>(end_l - begin_l);
    cout << "\List after insertion\n"; Show_list();
    cout << "Time spent in nanoseconds: " << elepsed_l.count() << "\n\n";

}

void Task_del_time(int*& mas_dyn, int& N)
{
    int ch = 0, e, pr;
    cout << "if insert in array by value enter 1 if at index enter 2\n";
    cout << "You choose: "; cin >> pr; cout << "\n\n" << "Array\n";
    Show_mas(mas_dyn, N); cout << "\n\n";
    if (pr == 1) { cout << "Enter the item to delete: "; cin >> e; ch = SerchInd_m(N, mas_dyn, e); cout << "\n"; }
    if (pr == 2) { cout << "Enter index to delete: "; cin >> ch; cout << "\n"; }

    auto begin_m = steady_clock::now();
    Del_mas(N, mas_dyn, ch);
    auto end_m = steady_clock::now();
    auto elepsed_m = duration_cast<nanoseconds>(end_m - begin_m);
    cout << "Array after element has been removed\n"; Show_mas(mas_dyn, N);
    cout << "\n\nTime spent in nanoseconds: " << elepsed_m.count() << "\n\n\n";

    cout << "\nif insert in list by value enter 1 if at index enter 2\n";
    cout << "You choose: "; cin >> pr; cout << "\n" << "list\n";
    Show_list();
    if (pr == 1) { cout << "Enter the item to delete: "; cin >> e; ch = SerchInd_l(e); cout << "\n"; }
    if (pr == 2) { cout << "Enter index to delete: "; cin >> ch; cout << "\n"; }

    auto begin_l = steady_clock::now();
    Del_list(ch);
    auto end_l = steady_clock::now();
    auto elepsed_l = duration_cast<nanoseconds>(end_l - begin_l);
    cout << "List after element has been removed\n"; Show_list();
    cout << "Time spent in nanoseconds: " << elepsed_l.count() << "\n\n";
}

void Add(int*& mas_dyn, int& N)
{
    int ch = 0, e, pr;
    cout << "\n" << "Array\n";
    Show_mas(mas_dyn, N); cout << "\n\n";

    auto begin_m = steady_clock::now();
    for (int i = 0; i < N; i++) {
        Del_mas(N, mas_dyn, i);
    }
    auto end_m = steady_clock::now();
    auto elepsed_m = duration_cast<nanoseconds>(end_m - begin_m);

    cout << "Array after element has been removed\n"; Show_mas(mas_dyn, N);
    cout << "\n\nTime spent in nanoseconds: " << elepsed_m.count() << "\n\n\n";

    cout << "\n" << "list\n";
    Show_list();

    auto begin_l = steady_clock::now();
    for (int i = 0; i < N; i++) {
        Del_list(i);
    }
    auto end_l = steady_clock::now();
    auto elepsed_l = duration_cast<nanoseconds>(end_l - begin_l);
    cout << "List after element has been removed\n"; Show_list();
    cout << "Time spent in nanoseconds: " << elepsed_l.count() << "\n\n";
}

void Task_find_time(int*& mas_dyn, int& N)
{
    int Find_m, Fch_m, Find_l, Fch_l, choose_;

    cout << "If you need to get the index of the entered number, press 1,if the number with a specific index, press 2\n";
    cout << "You choose: "; cin >> choose_;
    //получение числа 
    if (choose_ == 1)
    {
        cout << "\n\nArray\n";
        Show_mas(mas_dyn, N); cout << "\n\n";
        cout << "\nEnter number: "; cin >> Fch_m;
        cout << "Number index: ";
        auto begin_m = steady_clock::now();
        cout << SerchInd_m(N, mas_dyn, Fch_m);
        auto end_m = steady_clock::now();
        auto elepsed_m = duration_cast<nanoseconds>(end_m - begin_m);
        cout << "\n\nTime spent in nanoseconds: " << elepsed_m.count();

        cout << "\n\n\nlist\n";
        Show_list(); cout << "\n";
        cout << "Enter number: "; cin >> Fch_l;
        cout << "Number with index: ";
        auto begin_l = steady_clock::now();
        cout << SerchInd_l(Fch_l);
        auto end_l = steady_clock::now();
        auto elepsed_l = duration_cast<nanoseconds>(end_l - begin_l);
        cout << "\n\nTime spent in nanoseconds: " << elepsed_l.count() << "\n\n";
    }
    //получение индекса
    if (choose_ == 2)
    {
        cout << "\n\nArray\n";
        Show_mas(mas_dyn, N); cout << "\n\n";
        cout << "\nEnter index: "; cin >> Find_m;
        auto begin_m = steady_clock::now();
        cout << "Number: ";
        cout << SerchData_m(N, mas_dyn, Find_m);
        auto end_m = steady_clock::now();
        auto elepsed_m = duration_cast<nanoseconds>(end_m - begin_m);
        cout << "\n\nTime spent in nanoseconds: " << elepsed_m.count() << "\n\n";

        cout << "\n\n\nlist\n";
        Show_list(); cout << "\n";
        cout << "Enter index: "; cin >> Find_l;
        cout << "Number: ";
        auto begin_l = steady_clock::now();
        cout << SerchData_l3(Find_l);
        auto end_l = steady_clock::now();
        auto elepsed_l = duration_cast<nanoseconds>(end_l - begin_l);
        cout << "\n\nTime spent in nanoseconds: " << elepsed_l.count() << "\n\n";
    }
}


void PW2()
{
    int N = 100, fill, task;
    int* mas_dyn = new int[N];

    cout << "Forming an integer one-dimensional array and a doubly connected list of dimension N, where: \n\n";
    cout << "1) the user enters the number of elements in the array, which will be automatically filled with random numbers (0 to 99);\n";
    cout << "2) the user enters the array elements into the console, N is determined automatically by the number of elements entered;\n\n";
    cout << "3) * an array is read from a file, N is defined as the number of array elements in the file.\n\n";
    cout << "You entered: ";
    cin >> fill; cout << "\n\n";
    system("pause"); system("cls");

    switch (fill)
    {
    case 1:
        cout << "Enter the number of items\n" << "You entered: ";
        cin >> N; cout << "\n\n";
        Task_fill_time1(mas_dyn, N);
        break;
    case 2:
        N = 0;
        Task_fill_time2(mas_dyn, N);
        break;
    case 3:
        Task_fill_time3(mas_dyn, N);
        break;
    }

    cout << "\n\n";

    do
    {
        cout << "Choose a task:\n";
        cout << "1) Comparison of insert time\n";
        cout << "2) Comparison of delete time\n";
        cout << "3) Comparison of time of receipt\n";
        cout << "4) Removing even and odd elements\n";
        cout << "Exit - 0\n\n";
        cout << "You entered: "; cin >> task;
        system("cls");
        switch (task)
        {
        case 1:
            Task_insert_time(mas_dyn, N);
            system("pause"); system("cls");
            break;
        case 2:
            if (count_ == 0 && N == 0) { cout << "List and array is empty"; system("pause"); system("cls"); break; }
            if (count_ == 0) { cout << "List is empty"; system("pause"); system("cls"); break; }
            if (N == 0) { cout << "Array is empty"; system("pause"); system("cls"); break; }
            Task_del_time(mas_dyn, N);
            system("pause"); system("cls");
            break;

        case 3:
            Task_find_time(mas_dyn, N);
            system("pause"); system("cls");
            break;

        case 4:
            if (count_ == 0 && N == 0) { cout << "List and array is empty"; system("pause"); system("cls"); break; }
            if (count_ == 0) { cout << "List is empty"; system("pause"); system("cls"); break; }
            if (N == 0) { cout << "Array is empty"; system("pause"); system("cls"); break; }
            Add(mas_dyn, N);
            system("pause"); system("cls");
            break;

        case 0:
            break;
        }

    } while (task != 0);

    while (head) {
        tail = head->next;
        delete head;
        head = tail;
    }

    delete[] mas_dyn;
}

int priority(char o)
{
    switch (o)
    {
    case '(': return 1;
    case '+': case '-': return 2;
    case '*': case '/': return 3;
    }
}

bool sign(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/';
}

bool num(char c)
{
    return c >= '0' && c <= '9';
}

void RPN(char* a, char* out)
{
    stack <char> S;
    int i = 0, j = 0;
    for (; a[i] != '\0'; ++i)
    {
        if (num(a[i]))
        {
            out[j] = a[i];
            ++j;
        }
        else
        {
            if (j != 0 && num(out[j - 1]))
            {
                out[j] = ' ';
                ++j;
            }

            if (sign(a[i]))
            {
                if (S.empty() || priority(S.top()) < priority(a[i]))
                {
                    S.push(a[i]);
                }
                else
                {
                    while (!S.empty() && (priority(S.top()) >= priority(a[i])))
                    {
                        out[j++] = S.top();
                        S.pop();
                    }
                    S.push(a[i]);
                }
            }
            else
            {
                if (a[i] == '(')
                {
                    S.push(a[i]);
                }
                else if (a[i] == ')')
                {
                    if (S.empty() || S.top() == '(')
                    {
                        cout << "Input error!";
                        exit(1);
                    }
                    else
                    {
                        while (S.top() != '(')
                        {
                            out[j] = S.top();
                            S.pop();
                            j++;
                        }
                    }
                    S.pop();
                }
                else if (a[i] != ' ')
                {
                    cout << "Initialize the variable " << a[i] << ":  ";
                    cin >> a[i];
                    i--;
                }
            }
        }
    }
    while (!S.empty())
    {
        if (S.top() == '(')
        {
            cout << "Input error!";
            exit(1);
        }
        else
        {
            out[j] = S.top();
            S.pop();
            j++;
        }
    }
}

int calc(char* out)
{
    int j = 0, r1 = 0, r2 = 0;
    stack <double> S;
    stack <double> S1;
    char* pEnd = nullptr;
    while (out[j] != '\0')
    {
        if (out[j] == '_') {
            ++j;
            continue;
        }
        if (out[j] >= '0' && out[j] <= '9')
        {
            long iNum = strtol(&out[j], &pEnd, 10);
            S.push(iNum);
            j += pEnd - &out[j];
        }
        else
        {
            if (sign(out[j]))
            {
                if (S.empty()) return false;
                else {
                    r1 = S.top(); S.pop();
                    if (S.empty()) return false;
                    r2 = S.top(); S.pop();
                    switch (out[j])
                    {
                    case '+': S.push(r2 + r1); break;
                    case '-': S.push(r2 - r1); break;
                    case '*': S.push(r2 * r1); break;
                    case '/': S.push(r2 / r1); break;
                    }
                }
            }
            ++j;
        }
    }
    return (S.top());
}

bool check(char* a) {

    bool right = true;
    if (a[0] == '+' || a[0] == '*' || a[0] == '/') {
        right = false;
    }
    else if (a[strlen(a) - 1] == '+' || a[strlen(a) - 1] == '-' || a[strlen(a) - 1] == '*' || a[strlen(a) - 1] == '/') {
        right = false;
    }
    else {
        for (int i = 0; i < strlen(a); i++) {
            if ((a[i] == '+' || a[i] == '-' || a[i] == '*' || a[i] == '/') && (a[i + 1] == '+' || a[i + 1] == '*' || a[i + 1] == '/')) {
                right = false;
            }
            if ((a[i] == '/') && (a[i + 1] == '0')) {
                right = false;
            }
        }
    }
    return right;
}

void ex1() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "1. Converting the entered expression: " << endl;

    char a[100] = { 0 };
    char out[100] = { 0 };

    cout << "Expression: ";
    gets_s(a);
    RPN(a, out);
    cout << "RPN: " << out << endl << endl;

}

void ex2_1() {
    cout << endl << "2.  1)Checking for the correctness of a simple expression: " << endl;

    char chek[100] = { 0 };

    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Expression:  ";
    gets_s(chek);
    if (check(chek)) cout << "The expression is correct!" << endl;
    else cout << "The expression is incorrect!" << endl;

}

void ex2_2() {
    cout << endl << "    2)Checking the RPN" << endl;

    char chek[100] = { 0 };
    //char cheked[100] = { 0 };

    cout << "Expression:  ";
    gets_s(chek);
    //OPN(chek, cheked);
    if (calc(chek)) cout << "The expression is correct!" << endl;
    else cout << "The expression is incorrect!" << endl;

}

void ex3_1() {
    cout << endl << "3.  1)Evaluating a simple expression" << endl;

    char a[100] = { 0 };
    char out[100] = { 0 };

    cout << "Expression: ";
    gets_s(a);
    RPN(a, out);
    cout << "Answer:  " << calc(out) << endl << endl;

}

void ex3_2() {
    cout << endl << "    2)Evaluating a RPN" << endl;

    char a[100] = { 0 };

    cout << "Expression: ";
    gets_s(a);
    cout << "Answer:  " << calc(a) << endl << endl;
    system("pause");
}

void PW3()
{
    cout << "Expression input is implemented only from the keyboard" << endl << endl;

    ex1();
    ex2_1();
    ex2_2();
    ex3_1();
    ex3_2();
    system("cls");
}

int main()
{
	int practicalWork = 1;
	while (practicalWork != 0) {
		system("CLS");
		cout << "To choose Practical work, Enter the number of practical work or enter 0 for exit: \n";
		cout << "\t1) Study and organization of structures \n";
		cout << "\t2) Exploring the properties and organization of dynamic arrays and doubly linked lists \n";
        cout << "\t3) Polish notation. Stack and queue \n";
		cin >> practicalWork;
		switch (practicalWork) {
		case 1:
			system("CLS");
			PW1();
			break;
		case 2:
			system("CLS");
			PW2();
			break;
        case 3:
            system("CLS");
            PW3();
            break;
		case 0:
			cout << "Have a nice day!\n";
			break;
		default:
			cout << "Oh, no! This task doesn't exist. Let's try again.\n";
			break;
		}
	}
	return 0;
}