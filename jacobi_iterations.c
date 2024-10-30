#include<stdio.h>
#include<math.h>
int main()
{
    int tz,ty,tx,num=1,nvar;
    float a1,a2,a3,a4,ta,b1,b2,b3,b4,tb,c1,c2,c3,c4,tc,const1,const2,const3,const4,tempconst,xn,yn,zn,g,h,k;
    printf("enter coeff of x,y,z and constant in first equation");
    scanf("%f %f %f %f",&a1,&b1,&c1,&const1);
    printf("enter coeff of x,y,z and constant in second equation");
    scanf("%f %f %f %f",&a2,&b2,&c2,&const2);
    printf("enter coeff of x,y,z and constant in third equation");
    scanf("%f %f %f %f",&a3,&b3,&c3,&const3);
    printf("x\t\ty\t\tz\n");
    float x1=0,y1=0,z1=0,z2=0;
    if(nvar!=3 && nvar!=4)

    //checking diagonal
    if(fabs(a1)>(fabs(b1)+fabs(c1)) && fabs(b2)>(fabs(a2)+fabs(c2)) && fabs(c3)>(fabs(a3)+fabs(b3)))
    {
        printf("matrix is diagonal dominant\n");
    }
    if(fabs(a1)>(fabs(b1)+fabs(c1)))
    {
        printf("1\n");
        if(fabs(b2)<fabs(a2)+fabs(c2))
        {
            ta=a3,tb=b3,tc=c3,tempconst=const3;
            a3=a2,b3=b2,c3=c2,const3=const2;
            a2=ta,b2=tb,c2=tc,const2=tempconst;
        }
    }
    else if(fabs(b2)>(fabs(a2)+fabs(c2)))
    {
        printf("2\n");
        if(fabs(a1)<fabs(b1)+fabs(c1))
        {
            ta=a1,tb=b1,tc=c1,tempconst=const1;
            a1=a3,b1=b3,c1=c3,const1=const3;
            a3=ta,b3=tb,c3=tc,const3=tempconst;
        }
    }
    else if(fabs(c3)>(fabs(a3)+fabs(b2)))
    {
        printf("3\n");
        if(fabs(a1)<fabs(b1)+fabs(c1))
        {
            ta=a1,tb=b1,tc=c1,tempconst=const1;
            a1=a2,b1=b2,c1=c2,const1=const2;
            a2=ta,b2=tb,c2=tc,const2=tempconst;
        }
    else if(c1>a1+b1)
    {
        ta=a1,tb=b1,tc=c1,tempconst=const1;
        a1=a2,b1=b2,c1=c2,const1=const2;
        a2=a3,b2=b3,c2=c3,const2=const3;
        a3=ta,b3=tb,c3=tc,const3=tempconst;
    }
    else if(b1>a1+c1)
    {
        ta=a1,tb=b1,tc=c1,tempconst=const1;
        a1=a3,b1=b3,c1=c3,const1=const3;
        a3=a2,b3=b2,c3=c2,const3=const2;
        a2=ta,b2=tb,c2=tc,const2=tempconst;

    }   
    }
    while(1)
    {
        xn=(const1-(y1*b1)-(z1*c1))/a1;
        yn=(const2-(x1*a2)-(z1*c2))/b2;
        zn=(const3-(a3*x1)-(b3*y1))/c3;

        xn=roundf(xn*1000)/(float)1000;
        yn=roundf(yn*1000)/(float)1000;
        zn=roundf(zn*1000)/(float)1000;
        printf("%.4f\t%.4f\t%.4f\n",xn,yn,zn);

        if(x1==xn && y1==yn && z1==zn)
        {
            break;
        }
        
        x1=xn;
        y1=yn;
        z1=zn;
        num=num+1;
    }
    printf("number of iterations= %d\n",num);
    printf("the value of x is %.4f ,y is %.4f ,z is %.4f\n",xn,yn,zn);
    return (0);
}