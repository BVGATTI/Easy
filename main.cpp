#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class LinkNode {
public:
    string str;
    int len;
    LinkNode *next;

    explicit LinkNode(const string &s) {
        len = (int) s.length();
        str = s;
        next = nullptr;
    }
};

class LinkList {
public:
    void Enter(const string &s);

    LinkNode *GiveHead();

    LinkList() {
        l = 0;
        head = tail = nullptr;
    }

    void EmptyHead();

    int l;
private:
    LinkNode *head, *tail;
};

void LinkList::EmptyHead() {
    head = nullptr;
}

LinkNode *LinkList::GiveHead() {
    return head;
}

void LinkList::Enter(const string &s) {
    auto *p = new LinkNode(s);
    if (head == nullptr) {
        head = tail = p;
    } else {
        tail->next = p;
        tail = p;
    }
    l++;
}

class TextEditor {
public:
    void Create();

    void MoveCursor();

    void Add();

    void Insert();

    void Find();

    void Delete();

    int Count();

    void Show();

    void Write();

    void Read();

    void ShowCursor() const;

    void Empty();

    TextEditor() {
        cursor = line = 1;
        total = 0;
    }

private:
    LinkList text;
    int cursor;
    int line;
    int total;
    string name;
};

void TextEditor::Empty() {
    text.EmptyHead();
}

void TextEditor::ShowCursor() const {
    cout << "当前光标位于第" << line << "行的第" << cursor << "位";
    getchar();
}

void TextEditor::Read() {
    cout << "将文件中内容载入并清空原本内容" << endl;
    Empty();
    cout << "请输入要读入的文件名(带后缀.txt)" << endl;
    cin >> name;
    ifstream infile(name);
    string s;
    if (!infile.is_open()) {
        cout << "打开失败或无此文件(回车确认)" << endl;
        getchar();
    } else {
        while (true) {
            if (infile.eof() != 1) {
                getline(infile, s);
                text.Enter(s);
            } else if (infile.eof() == 1) {
                if (text.GiveHead() == nullptr) {
                    cout << "文件为空" << endl;
                    break;
                } else {
                    cout << "读取完毕(回车确认)" << endl;
                    getchar();
                    break;
                }
            }
        }
    }
}

void TextEditor::Write() {
    cout << "请输入要写出的文件名" << endl;
    cout << "后缀为.txt" << endl;
    cin >> name;
    ofstream outfile(name);
    LinkNode *p = text.GiveHead();
    while (p) {
        outfile << p->str;
        outfile << "\r\n";
        p = p->next;
    }
}

int TextEditor::Count() {
    LinkNode *p = text.GiveHead();
    char c;
    int count = 0;
    cout << "请输入要统计的字符" << endl;
    cin >> c;
    while (p) {
        for (char i : p->str) {
            if (i == c) {
                count++;
            }
        }
        total += p->len;
        p = p->next;
    }
    cout << "共有字符" << c << count << "个" << endl;
    cout << "该文档共有" << total << "个字符" << endl;
    return count;
}

void TextEditor::Show() {
    LinkNode *p = text.GiveHead();
    cout << "文档为：" << endl;
    while (p) {
        cout << p->str << endl;
        p = p->next;
    }
}

void TextEditor::Create() {
    string s;
    cout << "请输入字符串(Ctrl+Z停止输入)" << endl;
    while (getline(cin, s)) {
        text.Enter(s);
    }
}

void TextEditor::MoveCursor() {
    int n, i;
    cout << "请输入移动到的行数" << endl;
    cin >> n;
    if (n < 0 || n > text.l) {
        cout << "输入行数无效，当前行数不变" << endl;
    } else {
        line = n;
    }
    cout << "请输入光标在该行的位置" << endl;
    cin >> n;
    i = 0;
    LinkNode *p = text.GiveHead();
    while (i < line && p->next) {
        p = p->next;
    }

    if (n < 0) {
        cout << "输入光标位置无效，当前光标位置为1位" << endl;
    } else if (p && n > p->len) {
        cout << "输入光标位置无效，当前光标位置为位" << endl;
    } else if (p && n < p->len) {
        cursor = n;
    }
    cout << "当前光标位置为" << line << "行" << "第" << cursor << "位" << endl;
}

void TextEditor::Add() {
    string s;
    cout << "请输入要追加的字符串" << endl;
    cin >> s;
    text.Enter(s);
}

void TextEditor::Insert() {
    string s;
    cout << "将插入到当前光标所在行或所在处" << endl;
    cout << "若想插入其他位置，请先设定光标位置" << endl;
    cout << "请输入要插入的字符串" << endl;
    cin >> s;
    char c;
    cout << "是否插入当前行后（否则插入本行）？(y)" << endl;
    cin >> c;
    if (c == 'y') {
        int i = 1;
        LinkNode *p = text.GiveHead();
        cout << "line=" << line << endl;
        while (i < line) {
            p = p->next;
            i++;
        }
        auto *temp = new LinkNode(s);
        temp->next = p->next;
        p->next = temp;
    } else if (c == 'n') {
        int i = 1;
        LinkNode *p = text.GiveHead();
        while (i < line) {
            p = p->next;
            i++;
        }
        i = cursor;
        int j = 0;
        while (s[j]) {
            p->str[i] = s[j];
            i++;
            j++;
        }
        while (i < p->len) {
            p->str[i] = '\0';
            i++;
        }

        auto *temp1 = new LinkNode(p->str);
        temp1->next = p->next;
    } else {
        cout << "输入错误，返回主菜单" << endl;
        getchar();
    }
}

int NaiveStrMatching(string &T, string &P);

void TextEditor::Find() {
    string s;
    int n = 1;
    LinkNode *p = text.GiveHead();
    cout << "请输入查找的字符串" << endl;
    cin >> s;
    while (p) {
        if (NaiveStrMatching(p->str, s) > 0) {
            cout << "首次出现在第" << n << "行" << NaiveStrMatching(p->str, s) << "位置" << endl;
            break;
        }
        n++;
        p = p->next;
    }
    if (p == nullptr) {
        cout << "无此子串" << endl;
    }
}

int NaiveStrMatching(string &T, string &P) {
    int p = 0;
    int t = 0;
    int plen = (int) P.length();
    int tlen = (int) T.length();
    if (tlen < plen) {
        return -1;
    }
    while (p < plen && t < tlen) {
        if (T[t] == P[p]) {
            p++;
            t++;
        } else {
            t = t - p + 1;
            p = 0;
        }
    }
    if (p >= plen) {
        return t - plen + 1;
    } else {
        return -1;
    }
}

void TextEditor::Delete() {
    char c;
    cout << "是否删除行（否则删除某字符串）？（y）" << endl;
    cin >> c;
    if (c == 'y') {
        int n, i = 1;
        cout << "删除第几行？" << endl;
        cin >> n;
        LinkNode *p = text.GiveHead();
        while (i < n - 1) {
            p = p->next;
        }

        LinkNode *temp = p->next;
        p->next = temp->next;
        delete temp;
    } else if (c == 'n') {
        LinkNode *p = text.GiveHead();
        string s;
        cout << "请输入要删除的字符串" << endl;
        cin >> s;
        int n = 1, m;
        while (true) {
            if (NaiveStrMatching(p->str, s) > 0) {
                m = NaiveStrMatching(p->str, s);
                break;
            }
            n++;
            p = p->next;
        }
        p->str.erase(m - 1, s.length());
    } else {
        cout << "输入错误，返回主菜单" << endl;
        getchar();
    }
}

int flag = 0;

void Menu() {
    TextEditor text;
    int n;
    cout << "**********************************************" << endl
         << "***********简易文本编辑器(EasyText)************" << endl
         << "*********1、从文件中读入信息到EasyText**********" << endl
         << "*******************2、创建********************" << endl
         << "*****************3、追加内容******************" << endl
         << "*****************4、插入内容******************" << endl
         << "***************5、改变指针位置****************" << endl
         << "*******************6、查找********************" << endl
         << "*******************7、删除********************" << endl
         << "******************8、写文件*******************" << endl
         << "*******************9、计数********************" << endl
         << "******************10、显示********************" << endl
         << "***************11、显示光标位置***************" << endl
         << "******************12、退出********************" << endl
         << "**********************************************" << endl
         << endl
         << endl
         << "请选择(1-12)" << endl;
    cin >> n;
    switch (n) {
        case 1:
            text.Read();
            getchar();
            break;
        case 2:
            text.Create();
            getchar();
            break;
        case 3:
            text.Add();
            getchar();
            break;
        case 4:
            text.Insert();
            getchar();
            break;
        case 5:
            text.MoveCursor();
            getchar();
            break;
        case 6:
            text.Find();
            getchar();
            getchar();
            break;
        case 7:
            text.Delete();
            getchar();
            break;
        case 8:
            text.Write();
            getchar();
            break;
        case 9:
            text.Count();
            getchar();
            getchar();
            break;
        case 10:
            text.Show();
            getchar();
            getchar();
            break;
        case 11:
            text.ShowCursor();
            getchar();
            getchar();
            break;
        case 12:
            flag = 1;
            break;
        default:
            cout << "输入错误，请重新输入" << endl;
            getchar();
            getchar();
    }
}

int main() {
    while (true) {
        Menu();
        system("cls");
        if (flag) break;
    }
    return 0;
}