#ifndef INSERT_SORT_REC_H_INCLUDED
#define INSERT_SORT_REC_H_INCLUDED

template<typename T>
void insert_sort(T &obj, int p, int q)
{
    if(q>p)
    {
        insert_sort(obj, p, q-1);
        int key=obj.at(q);
        int i;

        for(i=q-1; i>=0 && obj.at(i)>key; i--)
        obj.at(i+1)=obj.at(i);

        obj.at(i+1)=key;
    }
}



#endif // INSERT_SORT_REC_H_INCLUDED
