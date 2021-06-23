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
    cout << "��ǰ���λ�ڵ�" << line << "�еĵ�" << cursor << "λ";
    getchar();
}

void TextEditor::Read() {
    cout << "���ļ����������벢���ԭ������" << endl;
    Empty();
    cout << "������Ҫ������ļ���(����׺.txt)" << endl;
    cin >> name;
    ifstream infile(name);
    string s;
    if (!infile.is_open()) {
        cout << "��ʧ�ܻ��޴��ļ�(�س�ȷ��)" << endl;
        getchar();
    } else {
        while (true) {
            if (infile.eof() != 1) {
                getline(infile, s);
                text.Enter(s);
            } else if (infile.eof() == 1) {
                if (text.GiveHead() == nullptr) {
                    cout << "�ļ�Ϊ��" << endl;
                    break;
                } else {
                    cout << "��ȡ���(�س�ȷ��)" << endl;
                    getchar();
                    break;
                }
            }
        }
    }
}

void TextEditor::Write() {
    cout << "������Ҫд�����ļ���" << endl;
    cout << "��׺Ϊ.txt" << endl;
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
    cout << "������Ҫͳ�Ƶ��ַ�" << endl;
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
    cout << "�����ַ�" << c << count << "��" << endl;
    cout << "���ĵ�����" << total << "���ַ�" << endl;
    return count;
}

void TextEditor::Show() {
    LinkNode *p = text.GiveHead();
    cout << "�ĵ�Ϊ��" << endl;
    while (p) {
        cout << p->str << endl;
        p = p->next;
    }
}

void TextEditor::Create() {
    string s;
    cout << "�������ַ���(Ctrl+Zֹͣ����)" << endl;
    while (getline(cin, s)) {
        text.Enter(s);
    }
}

void TextEditor::MoveCursor() {
    int n, i;
    cout << "�������ƶ���������" << endl;
    cin >> n;
    if (n < 0 || n > text.l) {
        cout << "����������Ч����ǰ��������" << endl;
    } else {
        line = n;
    }
    cout << "���������ڸ��е�λ��" << endl;
    cin >> n;
    i = 0;
    LinkNode *p = text.GiveHead();
    while (i < line && p->next) {
        p = p->next;
    }

    if (n < 0) {
        cout << "������λ����Ч����ǰ���λ��Ϊ1λ" << endl;
    } else if (p && n > p->len) {
        cout << "������λ����Ч����ǰ���λ��Ϊλ" << endl;
    } else if (p && n < p->len) {
        cursor = n;
    }
    cout << "��ǰ���λ��Ϊ" << line << "��" << "��" << cursor << "λ" << endl;
}

void TextEditor::Add() {
    string s;
    cout << "������Ҫ׷�ӵ��ַ���" << endl;
    cin >> s;
    text.Enter(s);
}

void TextEditor::Insert() {
    string s;
    cout << "�����뵽��ǰ��������л����ڴ�" << endl;
    cout << "�����������λ�ã������趨���λ��" << endl;
    cout << "������Ҫ������ַ���" << endl;
    cin >> s;
    char c;
    cout << "�Ƿ���뵱ǰ�к󣨷�����뱾�У���(y)" << endl;
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
        cout << "������󣬷������˵�" << endl;
        getchar();
    }
}

int NaiveStrMatching(string &T, string &P);

void TextEditor::Find() {
    string s;
    int n = 1;
    LinkNode *p = text.GiveHead();
    cout << "��������ҵ��ַ���" << endl;
    cin >> s;
    while (p) {
        if (NaiveStrMatching(p->str, s) > 0) {
            cout << "�״γ����ڵ�" << n << "��" << NaiveStrMatching(p->str, s) << "λ��" << endl;
            break;
        }
        n++;
        p = p->next;
    }
    if (p == nullptr) {
        cout << "�޴��Ӵ�" << endl;
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
    cout << "�Ƿ�ɾ���У�����ɾ��ĳ�ַ���������y��" << endl;
    cin >> c;
    if (c == 'y') {
        int n, i = 1;
        cout << "ɾ���ڼ��У�" << endl;
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
        cout << "������Ҫɾ�����ַ���" << endl;
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
        cout << "������󣬷������˵�" << endl;
        getchar();
    }
}

int flag = 0;

void Menu() {
    TextEditor text;
    int n;
    cout << "**********************************************" << endl
         << "***********�����ı��༭��(EasyText)************" << endl
         << "*********1�����ļ��ж�����Ϣ��EasyText**********" << endl
         << "*******************2������********************" << endl
         << "*****************3��׷������******************" << endl
         << "*****************4����������******************" << endl
         << "***************5���ı�ָ��λ��****************" << endl
         << "*******************6������********************" << endl
         << "*******************7��ɾ��********************" << endl
         << "******************8��д�ļ�*******************" << endl
         << "*******************9������********************" << endl
         << "******************10����ʾ********************" << endl
         << "***************11����ʾ���λ��***************" << endl
         << "******************12���˳�********************" << endl
         << "**********************************************" << endl
         << endl
         << endl
         << "��ѡ��(1-12)" << endl;
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
            cout << "�����������������" << endl;
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