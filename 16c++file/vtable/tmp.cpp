 /*Base1's vtable*/
        pFun=(Fun)pVtab[0][0];
        pFun();
        pFun=(Fun)pVtab[0][1];
        pFun();
        pFun=(Fun)pVtab[0][2];
        pFun();
        
        /*Drive's table*/
        pFun=(Fun)pVtab[0][3];
        pFun();
        /*the tail of the vtable*/
        pFun=(Fun)pVtab[0][4];
        cout<<pFun<<endl;
        printf("pFun=%p\n",pFun);
        cout<<"Baes1::base1="<<(long)(* pVtab[1]);
        /*Base2's vtable*/
        pFun=(Fun)pVtab[2][0];
        pFun();
        pFun=(Fun)pVtab[2][1];
        pFun();
        pFun=(Fun)pVtab[2][2];
        pFun();
        /*the tail of the vtable*/
        pFun=(Fun)pVtab[2][3];
        cout<<pFun<<endl;
        printf("pFun=%p\n",pFun);
        cout<<"Baes2::base2="<<(long)(*pVtab[3]);
        
        /*Base3's vtable */
        pFun=(Fun)pVtab[4][0];
        pFun();
        pFun=(Fun)pVtab[4][1];
        pFun();
        pFun=(Fun)pVtab[4][2];
        pFun();
        /*the tail of the vtable*/
        pFun=(Fun)pVtab[4][3];
        cout<<pFun<<endl;
        printf("pFun=%p\n",pFun);
        cout<<"Baes3::base3="<<(long)(*pVtab[5]);
        cout<<"Drive::drive="<<(long)(*pVtab[6]);
        */
