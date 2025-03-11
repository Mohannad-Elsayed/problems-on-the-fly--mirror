#include<iostream>
int main(){int a,b=715827882,c,d,e;for(std::cin>>a;a--;std::cin>>c>>d>>e,std::cout<<(~(b|e)*3&d-2*b)+((b&~e)*3&c-d+~b)+2*e)printf(" 0 %d ! ",b);}