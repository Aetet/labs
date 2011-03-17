//---------------------------------------------------------------------------
#include <string.h>
#include <stdlib.h>

#ifndef Unit2H
#define Unit2H
enum Token
{
        END = 0,
        TYPE_ID,
        TYPE_NUM,
        PLUS,
        MUL,
        MORE,
        LESS,
        EQUAL, //ASSIGNMENT
        BRACKET_OPEN,
        BRACKET_CLOSE,
        SEMICOLON,
        KEYWORD_IF,
        KEYWORD_ELSE,
        KEYWORD_ENDIF,
        KEYWORD_WHILE,
        KEYWORD_ENDLOOP,
        TS = 100,
        TSLIST,
        TEQUASION,
        TIF,
        TWHILE,
        TE,
        TELIST,
        TT,
        TTLIST,
        TF,
        TLOGIC,
        TLOGICEXPRESSION,
        EOM = 1000,
        FJZ,
        FJMP,
        FADD,
        FMUL,
        FCMP,
        FMOV,
        FLABEL,
        FNOP,
        FSTOP
};
class ArrayMap
{
        struct TId
        {
                char      key[255];
                int       val;
        } arr[255];
        int find(char str[255])
        {
                if(n==0)return -1;
                int s=0, k=n-1;
                do
                {
                        int j=(s+k)>>1;
                        if(strcmp(arr[j].key,str)<0) s=j+1;
                        else k=j;
                }
                while(s!=k);
                if(strcmp(arr[k].key,str)!=0)return -1;
                return (k);
        }
        int n;
        public:
        ArrayMap():n(0) {}
        void Add(char key[255], int val)
        {
                int i;
                for(i=0; i<n; i++)
                {
                        int a=strcmp(arr[i].key,key);
                        if(a==0)return;
                        if(a>0)break;
                }
                for(int j=n; i<=j; j--)
                {
                        arr[j+1]=arr[j];
                }
                strcpy(arr[i].key,key);
                arr[i].val=val;
                n++;
                return;
        }
        int& Search(char key[255])
        {
                int a= find(key);
                if (a==-1) throw "No such variable";
                return arr[a].val;
        }
        bool Delete(char key[255])
        {
                int k = find(key);
                if (k==-1) return false;
                for(int i=k; i<n-1; i++)
                {
                        arr[i]=arr[i+1];
                }
                n--;
                return true;
        }
        int& operator[](int i) { return arr[i].val; }
        struct iterator
        {
                TId* index;
                iterator(TId* i): index(i) {}
                char* operator * ()
                {
                        return index->key;
                }
                iterator operator ++ ()
                {
                        index++;
                        return (*this);
                }
                iterator operator ++ (int)
                {
                        index++;//sizeof(TId);
                        return iterator(index-1);
                }
                bool operator == (iterator a)
                {
                        return (index==a.index);
                }
                bool operator != (iterator a)
                {
                        return (index!=a.index);
                }
                int getval()
                {
                        return index->val;
                }
        } begin() { return iterator(arr); }
        iterator  end() { return iterator(&arr[n]); }
};

class LexReader
{
        //char b;
        char nextSymbol() { return input[position++]; }
        void stepBack() {position--;}
        bool isSpace(char b)
        {
                return ((b!=0)&&(b==' '||b=='\t'||b=='\r'||b=='\n'));
        }
        char NonSpace(char b)
        {
                while(isSpace(b)) {b=nextSymbol();}
                return b;
        }
        char skipValid(char* s, int t)
        {
                unsigned p=0;
                char b=nextSymbol();
                while(b==s[p])
                {
                        value[t++]=s[p++];
                        if(s[p]==0) return nextSymbol();
                        b=nextSymbol();
                }
                //throw Error(strcat(strcat(strcat(strcat(new char[130],"������ � �������� �����, ��������� "),s)," ������� "),value),position);
        }
        Token readID(int p)
        {
                //delete value;
                //value = new char[50];
                //unsigned p=0;
                //while(s[p]!=0){value[p]=s[p];p++;}
                char b=nextSymbol();
                while(b!=' '&&b!='\t'&&b!='\r'&&b!='\n'&&b!=0&&b!='+'&&b!='-'&&b!='*'&&b!='>'&&b!='<'&&b!=')'&&b!='('&&b!='='&&b!=';')
                {
                        value[p++]=b;
                        b=nextSymbol();
                }
                value[p]=0;
                stepBack();
                identifiers.Add(value,0);
                return TYPE_ID;
        }
        public:
        ArrayMap identifiers;
        struct Error
        {
                char* message;
                unsigned position;
                Error(char* m, unsigned p):message(m),position(p) {}
        };
        /// ������� �� ���������� ���������� �����
        char* input;
        unsigned position;
        ///

        char value[100];

        LexReader(char* sep):position(0),input(0)
        {
                input=new char[strlen(sep)+10];
                strcpy(input,sep);
        }
        Token nextToken()
        {
                char c;
                for(int i=0;i<100;i++)value[i]=0;
                value[0] = NonSpace(nextSymbol());
                switch(value[0])
                {
                        // ����������
                        case '+':return        PLUS;
                        case '*':return        MUL;
                        case '>':return        MORE;
                        case '<':return        LESS;
                        case '=':return        EQUAL;
                        case '(':return        BRACKET_OPEN;
                        case ')':return        BRACKET_CLOSE;
                        case ';':return        SEMICOLON;

                        // �����
                        case '0':
                        case '1':
                        case '2':
                        case '3':
                        case '4':
                        case '5':
                        case '6':
                        case '7':
                        case '8':
                        case '9':
                        {
                                //delete value;
                                //value = new char[50];
                                unsigned p=0;
                                //value[0]=c;
                                while(value[p]>='0'&&value[p]<='9'){value[++p]=nextSymbol();}
                                if(value[p]>='a'&&value[p]<='z'||value[p]>='A'&&value[p]<='Z') throw Error("������ ����� �����",position);
                                stepBack();
                                value[p]=0;
                                identifiers.Add(value,0);
                                return TYPE_NUM;
                        }

                        // �������� �����
                        case '�'://���

                                c=skipValid("���",1);
                                if(c==' '||c=='\t'||c=='\r'||c=='\n'||c==0||c=='(')
                                {       stepBack();
                                        return KEYWORD_IF;
                                }
                                return readID(4);
                        case '�'://����
                                 c=skipValid("����",1);
                                if(c==' '||c=='\t'||c=='\r'||c=='\n'||c==0)
                                {       stepBack();
                                        return KEYWORD_ELSE;
                                }
                                return readID(5);
                        case '�'://���_����
                                 c=skipValid("���_����",1);
                                if(c==' '||c=='\t'||c=='\r'||c=='('||c==0)
                                {       stepBack();
                                        return KEYWORD_WHILE;
                                }
                                return readID(9);
                        case '�'://����_(� ���, � ���)
                                 c=skipValid("����_",1);
                                switch(c)
                                {
                                   case '�':
                                        c=skipValid("���",6);
                                        if(c==0x88||c==' '||c=='\t'||c=='\r'||c=='\n'||c==0||c=='\x1E'||c=='\x10')
                                        {       stepBack();
                                                return KEYWORD_ENDLOOP;
                                        }
                                        //stepBack();
                                        return KEYWORD_ENDLOOP;
                                   case '�':
                                        c=skipValid("���",6);
                                        if(c==' '||c=='\t'||c=='\r'||c=='\n'||c==0)
                                        {       stepBack();
                                                return KEYWORD_ENDIF;
                                        }
                                        return readID(9);
                                   default:
                                        return readID(6);
                                }
                        // �������������
                        case 0:
                        case '\x1E':
                        case '\x10':
                        case '\x0E':
                        case 0x88:
                        case (-120):
                                return END;
                        default:
                                if(value[0]>='a'&&value[0]<='z'||value[0]>='A'&&value[0]<='Z')
                                return readID(1);
                                if(input[position+1]=='\0')return END;
                                throw Error("��� ������ �������", position);
                }
        }
};
//---------------------------------------------------------------------------
// ������������ ������ � 3
// ���������� ��������������� �����������
//---------------------------------------------------------------------------
class Parser
{
        struct TM //Token Magazine Node
        {
                Token t;
                TM* n;
        } *m;
        LexReader r;
        Token t;
        void a(Token tt)//��������� � �������
        {
                TM *mm = new TM();
                mm->t=tt;
                mm->n=m;
                m=mm;
        }
        void p1() //��������(<�������� ������������><S-������>), �������
        {
                a(TSLIST);
                a(TEQUASION);
        }
        void p2() //��������(<�������� ��������> <S-������>), �������
        {
                a(TSLIST);
                a(TIF);
        }
        void p3() //��������(<�������� �����> <S-������>), �������
        {
                a(TSLIST);
                a(TWHILE);
        }
        void p4() //��������(<S>), �������
        {
                a(TS);
        }
        void p5(){} //����������, �������
        void p6() //��������(=<E>;), �����
        {
                a(SEMICOLON);
                a(TE);
                a(EQUAL);
                t=r.nextToken(); //csdvig
        }
        void p7() //��������((<���.���>) <S> ����� <S> �����_����), �����
        {
                a(KEYWORD_ENDIF);
                a(TS);
                a(KEYWORD_ELSE);
                a(TS);
                a(BRACKET_CLOSE);
                a(TLOGICEXPRESSION);
                a(BRACKET_OPEN);
                t=r.nextToken();
        }
        void p8() //��������((<���.���.>) <S> �����_����), �����
        {
                a(KEYWORD_ENDLOOP);
                a(TS);
                a(BRACKET_CLOSE);
                a(TLOGICEXPRESSION);
                a(BRACKET_OPEN);
                t=r.nextToken();
        }
        void p9() //��������(<T><E-������>), �������
        {
                a(TELIST);
                a(TT);
        }
        void p10() //��������(<T><E-������>), �����
        {
                a(TELIST);
                a(TT);
                t=r.nextToken();
        }
        void p11(){} //����������, �������
        void p12() //��������(<F><T-������>), �������
        {
                a(TTLIST);
                a(TF);
        }
        void p13() //��������(<F><T-������>), �����
        {
                a(TTLIST);
                a(TF);
                t=r.nextToken();
        }
        void p14(){} //����������, �������
        void p15(){t=r.nextToken();} //����������,�����
        void p16(){t=r.nextToken();} //����������,�����
        void p17() //��������(<F><���.����.><F>), �������
        {
                a(TF);
                a(TLOGIC);
                a(TF);
        }
        void p18() {t=r.nextToken();} //����������,�����
        void p19() {t=r.nextToken();} //����������,�����
        void pop(Token tt) //����������,�����
        {
                if(t!=tt)throw Error(tt,t);
                t=r.nextToken();
        }
        public:
        Parser(char* sep):m(0),r(sep),t(END)
        {
                m = new TM();
                m->t=TS;
                m->n=new TM();
                m->n->t=EOM;
                m->n->n=0;
                t=r.nextToken();
        }
        struct Error
        {
                Token expected;
                Token found;
                Error(Token e,Token f):expected(e),found(f)
                {
                }
        };
        bool parse()
        {
                for(;;)
                {
                TM *mm = m->n;
                Token tt = m->t;
                delete m;
                m=mm;
                switch(tt)
                {
                case TS:
                        switch(t)
                        {
                                case TYPE_ID:p1();break;
                                case KEYWORD_IF:p2();break;
                                case KEYWORD_WHILE:p3();break;
                                default: throw Error(tt,t);
                        }
                        break;
                case TSLIST:
                        switch(t)
                        {
                                case TYPE_ID:
                                case KEYWORD_IF:
                                case KEYWORD_WHILE:p4();break;
                                case KEYWORD_ELSE:
                                case KEYWORD_ENDIF:
                                case KEYWORD_ENDLOOP:
                                case END:p5();break;
                                default: throw Error(tt,t);
                        }
                        break;
                case TEQUASION:
                        if(t==TYPE_ID) { p6();break; }
                        throw Error(tt,t);
                case TIF:
                        if(t==KEYWORD_IF) { p7();break; }
                        throw Error(tt,t);
                case TWHILE:
                        if(t==KEYWORD_WHILE) { p8();break; }
                        throw Error(tt,t);
                case TE:
                        switch(t)
                        {
                                case TYPE_ID:
                                case TYPE_NUM:p9();break;
                                default:throw Error(tt,t);
                        }
                        break;
                case TELIST:
                        switch(t)
                        {
                                case PLUS:p10();break;
                                case SEMICOLON:p11();break;
                                default:throw Error(tt,t);
                        }
                        break;
                case TT:
                        switch(t)
                        {
                                case TYPE_ID:
                                case TYPE_NUM:p12();break;
                                default:throw Error(tt,t);
                        }
                        break;
                case TTLIST:
                        switch(t)
                        {
                                case SEMICOLON:
                                case PLUS:p14();break;
                                case MUL:p13();break;
                                default:throw Error(tt,t);
                        }
                        break;
                case TF:
                        switch(t)
                        {
                                case TYPE_ID:p15();break;
                                case TYPE_NUM:p16();break;
                                default:throw Error(tt,t);
                        }
                        break;
                case TLOGIC:
                        switch(t)
                        {
                                case MORE:p18();break;
                                case LESS:p19();break;
                                default:throw Error(tt,t);
                        }
                        break;
                case TLOGICEXPRESSION:
                        switch(t)
                        {
                                case TYPE_ID:
                                case TYPE_NUM:p17();break;
                                default:throw Error(tt,t);
                        }
                        break;
                case EQUAL:pop(EQUAL);break;
                case BRACKET_OPEN:pop(BRACKET_OPEN);break;
                case BRACKET_CLOSE:pop(BRACKET_CLOSE);break;
                case SEMICOLON:pop(SEMICOLON);break;
                case KEYWORD_ELSE:pop(KEYWORD_ELSE);break;
                case KEYWORD_ENDIF:pop(KEYWORD_ENDIF);break;
                case KEYWORD_ENDLOOP:pop(KEYWORD_ENDLOOP);break;
                case EOM:if(t==END)return true;
                default: throw Error(tt,t);
                }
                }
        }

};
//---------------------------------------------------------------------------
// ������������ ������ � 4
// ���������� �����������
//---------------------------------------------------------------------------
class AttributeParser
{
        public:
        struct TM //Token Magazine Node
        {
                Token t;
                int p;
                int q;
                int s;
                int* r; //��������! �������� r - �����������!
                //����������� ��� �������� ����������.
                //������ ��������� �� ��������, ���� ����� �������� ����� ��������,
                //����� ����� �������� ���� ����� - ������, ��� �������� �������.
                TM* n;
                TM():r(0) {}
        } *m, *f, *flast;
        //���� ��������� ��������� ������������ ��� �������� ���������� � ��������,
        //� ����� ��� �������� ������� ��������. ����� ������� ����������� �������
        //�������� � �����-�� ������ �� ���� ����������� �� �������� ������.
        int n;
        private:
        Token t;
        void a(Token tt)//��������� � �������
        {
                TM *mm = new TM();
                mm->t=tt;
                mm->n=m;
                m=mm;
        }
        void v()
        {
                TM *mm = m->n;
                delete m;
                m=mm;
        }
        void p1() //��������(<�������� ������������><S-������>), �������
        {
                v();
                a(TSLIST);
                a(TEQUASION);
        }
        void p2() //��������(<�������� ��������> <S-������>), �������
        {
                v();
                a(TSLIST);
                a(TIF);
        }
        void p3() //��������(<�������� �����> <S-������>), �������
        {
                v();
                a(TSLIST);
                a(TWHILE);
        }
        void p4() //��������(<S>), �������
        {
                v();
                a(TS);
        }
        void p5(){v();} //����������, �������
        void p6() //��������(=<E>;{���������}), �����
        {
                int x=0;
                if (r.identifiers.Search(r.value)==0)
                {
                        r.identifiers.Search(r.value) = n;
                        x = n++;
                } else  x = r.identifiers.Search(r.value);
                v();
                a(SEMICOLON);
                a(FMOV);
                m->p=x;
                a(TE);
                m->r=&(m->n->q);
                a(EQUAL);
                t=r.nextToken(); //�����
        }
        void p7() //��������((<���.���>){������� �� 0} <S> ����� {������} {�����} <S> {�����} �����_����), �����
        {
                v();
                a(KEYWORD_ENDIF);
                a(FLABEL);
                TM* mm=m;
                a(TS);
                a(FLABEL);
                a(FJMP);
                mm->r=&(m->p);
                mm=m->n;
                a(KEYWORD_ELSE);
                a(TS);
                a(FJZ);
                mm->r=&(m->q);
                m->p=n++;
                mm=m;
                a(BRACKET_CLOSE);
                a(TLOGICEXPRESSION);
                m->r=&(mm->p);
                a(BRACKET_OPEN);
                t=r.nextToken();
        }
        void p8() //��������( ({�����}<���.���.>)  {�������� ������� �� 0} <S> {����������� �������} {�����} �����_����), �����
        {
                v();
                a(KEYWORD_ENDLOOP);
                a(FLABEL);
                a(FJMP);
                TM* mm=m;
                a(TS);
                a(FJZ);
                mm->n->r=&(m->q);
                m->p=n++;
                TM* mmm=m;
                a(BRACKET_CLOSE);
                a(TLOGICEXPRESSION);
                m->r=&(mmm->p);
                a(FLABEL);
                m->r=&(mm->p);
                a(BRACKET_OPEN);
                t=r.nextToken();
        }
        void p9() //��������(<T><E-������>), �������
        {
                int* x = m->r;//���� ������� ���������. ������� � ������ � ����������.
                v();
                a(TELIST);
                m->r=x;
                a(TT);
                m->r=&(m->n->p);
        }
        void p10() //��������(<T>{�������}<E-������>), �����
        {
                int p = m->p;
                int* rr = m->r;
                v();
                a(TELIST);
                m->r=rr;
                m->p=n; //�����������
                a(FADD);
                m->p=p;
                //m->r=&(m->n->p);  // <-------------------- �� �����
                m->s=n++;
                a(TT);
                m->r=&(m->n->q);
                t=r.nextToken();
        }
        void p11() //����������, �������
        {
                *(m->r)=m->p;
                v();
        }
        void p12() //��������(<F><T-������>), �������
        {
                int* x = m->r;
                v();
                a(TTLIST);
                m->r=x;
                a(TF);
                m->r=&(m->n->p);
        }
        void p13() //��������(<F>{��������}<T-������>), �����
        {
                int p = m->p;
                int* rr = m->r;
                v();
                a(TTLIST);
                m->r=rr;
                m->p=n; //�����������
                a(FMUL);
                m->p=p;
                //m->r=&(m->n->p);  // <-------------------- �� �����
                m->s=n++;
                a(TF);
                m->r=&(m->n->q);
                t=r.nextToken();
        }
        void p14() //����������, �������
        {
                *(m->r)=m->p;
                v();
        }
        void p15() //����������,�����
        {
                if (r.identifiers.Search(r.value)==0)
                {
                        r.identifiers.Search(r.value) = n;
                        *(m->r) = n++;
                } else  *(m->r) = r.identifiers.Search(r.value);
                v();
                t=r.nextToken();
        }
        void p16() //����������,�����
        {
                if (r.identifiers.Search(r.value)==0)
                {
                        r.identifiers.Search(r.value) = n;
                        *(m->r) = n++;
                } else  *(m->r) = r.identifiers.Search(r.value);
                v();
                t=r.nextToken();
        }
        void p17() //��������(<F><���.����.><F>{���������}), �������
        {
                int* x = m->r;
                v();
                a(FCMP);
                m->r=x;
                TM* mm=m;
                a(TF);
                m->r=&(mm->s);
                a(TLOGIC);
                m->r=&(mm->q);
                a(TF);
                m->r=&(mm->p);
        }
        void p18() //����������,�����
        {
                *(m->r)=1;//>
                v();
                t=r.nextToken();
        }
        void p19() //����������,�����
        {
                *(m->r)=-1;//<
                v();
                t=r.nextToken();
        }
        void pop(Token tt) //����������,�����
        {
                v();
                if(t==END)return;
                if(t!=tt)throw Error(tt,t);
                t=r.nextToken();
        }
        void act(Token tt)
        {
                //TM *mm = m->n;
                if(flast)flast->n=m;
                flast=m;
                if(!f)f=m;
                m=m->n;
                flast->n=0;
                /*code[coden].t=tt;
                code[coden].p=m->p;
                code[coden].q=m->q;
                if((m->r)!=0) code[coden].r=(*(m->r));
                code[coden].s=m->s; */
                coden++;
                //v();
        }
        public:
        /*struct tcode       //��� ����������� ���������� �������� �������� ��������
        {
                Token t;
                int p,q,s,r;
        } code[50];*/
        int coden;
        LexReader r;
        AttributeParser(char* sep):m(0),n(1),coden(0),r(sep),t(END), f(0), flast(0)
        {
                m = new TM();
                m->t=TS;
                m->n=new TM();
                m->n->t=EOM;
                m->n->n=0;
                t=r.nextToken();
        }
        struct Error
        {
                Token expected;
                Token found;
                Error(Token e,Token f):expected(e),found(f)
                {
                }
        };
        bool parse()
        {
                for(;;)
                {
                Token tt = m->t;
                switch(tt)
                {
                case TS:
                        switch(t)
                        {
                                case TYPE_ID:p1();break;
                                case KEYWORD_IF:p2();break;
                                case KEYWORD_WHILE:p3();break;
                                default: throw Error(tt,t);
                        }
                        break;
                case TSLIST:
                        switch(t)
                        {
                                case TYPE_ID:
                                case KEYWORD_IF:
                                case KEYWORD_WHILE:p4();break;
                                case KEYWORD_ELSE:
                                case KEYWORD_ENDIF:
                                case KEYWORD_ENDLOOP:
                                case END:p5();break;
                                default: throw Error(tt,t);
                        }
                        break;
                case TEQUASION:
                        if(t==TYPE_ID) { p6();break; }
                        throw Error(tt,t);
                case TIF:
                        if(t==KEYWORD_IF) { p7();break; }
                        throw Error(tt,t);
                case TWHILE:
                        if(t==KEYWORD_WHILE) { p8();break; }
                        throw Error(tt,t);
                case TE:
                        switch(t)
                        {
                                case TYPE_ID:
                                case TYPE_NUM:p9();break;
                                default:throw Error(tt,t);
                        }
                        break;
                case TELIST:
                        switch(t)
                        {
                                case PLUS:p10();break;
                                case SEMICOLON:p11();break;
                                default:throw Error(tt,t);
                        }
                        break;
                case TT:
                        switch(t)
                        {
                                case TYPE_ID:
                                case TYPE_NUM:p12();break;
                                default:throw Error(tt,t);
                        }
                        break;
                case TTLIST:
                        switch(t)
                        {
                                case SEMICOLON:
                                case PLUS:p14();break;
                                case MUL:p13();break;
                                default:throw Error(tt,t);
                        }
                        break;
                case TF:
                        switch(t)
                        {
                                case TYPE_ID:p15();break;
                                case TYPE_NUM:p16();break;
                                default:throw Error(tt,t);
                        }
                        break;
                case TLOGIC:
                        switch(t)
                        {
                                case MORE:p18();break;
                                case LESS:p19();break;
                                default:throw Error(tt,t);
                        }
                        break;
                case TLOGICEXPRESSION:
                        switch(t)
                        {
                                case TYPE_ID:
                                case TYPE_NUM:p17();break;
                                default:throw Error(tt,t);
                        }
                        break;
                case EQUAL:pop(EQUAL);break;
                case BRACKET_OPEN:pop(BRACKET_OPEN);break;
                case BRACKET_CLOSE:pop(BRACKET_CLOSE);break;
                case SEMICOLON:pop(SEMICOLON);break;
                case KEYWORD_ELSE:pop(KEYWORD_ELSE);break;
                case KEYWORD_ENDIF:pop(KEYWORD_ENDIF);break;
                case KEYWORD_ENDLOOP:pop(KEYWORD_ENDLOOP);break;
                case FADD:act(FADD);break;
                case FCMP:act(FCMP);break;
                case FJMP:act(FJMP);break;
                case FJZ:act(FJZ);break;
                case FMUL:act(FMUL);break;
                case FLABEL:    *(m->r)=coden;
                                act(FLABEL);break;
                case FMOV:act(FMOV);break;
                case EOM:if(t==END)return true;
                default: throw Error(tt,t);
                }
                }
        }

};

class Translator //������������� ���������� ����
{
        public:
        int mem[500];
        int n;
        int pos;
        struct Code
        {
                Token t;
                int p,q,r,s;
        }
        *code;
        Translator():n(0) {}
        ~Translator() { delete code; }
        void step(int &i, int &v, int &p)
        {
                Code c = code[pos];
                switch(c.t)
                {
                        case FADD:      i=c.s;
                                        mem[i]=mem[c.p]+mem[c.q];
                                        v=mem[i];
                                        pos++;
                                        break;
                        case FMUL:
                                        i=c.s;
                                        mem[i]=mem[c.p]*mem[c.q];
                                        v=mem[i];
                                        pos++;
                                        break;
                        case FCMP:
                                        i=c.r;
                                        mem[i]=int(c.q*mem[c.p]>c.q*mem[c.s]);
                                        v=mem[i];
                                        pos++;
                                        break;
                        case FMOV:
                                        i=c.p;
                                        mem[i]=mem[c.q];
                                        v=mem[i];
                                        pos++;
                                        break;
                        case FJZ:
                                        i=0;
                                        if(mem[c.p]==0)pos=c.q;
                                        else pos++;
                                        break;
                        case FJMP:
                                        i=0;
                                        pos=c.p;
                                        break;
                        case FLABEL:
                                        i=0;
                                        pos++;
                                        break;
                        case FSTOP:
                                        i=0;
                                        break;
                }
                p=pos;
        }
        void run()
        {
                int i=0, v=0, p=0;
                for(int j=0;j<10000;j++)
                {
                        if(code[pos].t==FSTOP)break;
                        step(i,v,p);
                }

        }
};

//---------------------------------------------------------------------------
#endif
