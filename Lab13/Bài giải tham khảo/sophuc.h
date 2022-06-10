typedef struct sophuc
{
    float thuc;
    float ao;
}sophuc;

void Nhap(sophuc *a)
{
    char t[100];
    printf("Nhap so so phuc: ");
    fgets(t,sizeof(t),stdin);
    sscanf(t,"%f %fi",&a->thuc,&a->ao);
}

void Xuat(sophuc a)
{
    if(a.ao>0)
        printf("%.2f+%.2fi\n",a.thuc,a.ao);
    else
        printf("%.2f%.2fi\n",a.thuc,a.ao);
}

sophuc Tong(sophuc a,sophuc b)
{
    sophuc t;
    t.thuc=a.thuc+b.thuc;
    t.ao=a.ao+b.ao;

    return t;
}

sophuc Hieu(sophuc a,sophuc b)
{
    sophuc t;
    t.thuc=a.thuc-b.thuc;
    t.ao=a.ao-b.ao;

    return t;
}

sophuc Tich(sophuc a,sophuc b)
{
    sophuc t;
    t.thuc=a.thuc*b.thuc-a.ao*b.ao;
    t.ao=a.ao*b.thuc+b.ao*a.thuc;

    return t;
}

sophuc Thuong(sophuc a,sophuc b)
{
    sophuc t;
    t.thuc=(a.thuc*b.thuc+a.ao*b.ao)/(a.thuc*a.thuc+b.ao*b.ao);
    t.ao=(a.ao*b.thuc-b.ao*a.thuc)/(a.thuc*a.thuc+b.ao*b.ao);

    return t;
}

float Argument(sophuc a)
{
    return atan(a.ao/a.thuc);
}

float Module(sophuc a)
{
    return sqrt(a.thuc*a.thuc+a.ao*a.ao);
}