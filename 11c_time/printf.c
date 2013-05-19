int max(int cnt,...)
{
        va_list v;
        va_start(v,cnt);
        int m=va_arg(v,int);
        for(int i=1;i<cnt;++i){
                j=va_arg(v,int);
        }
        va_end(v);
        return i;
}
