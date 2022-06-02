#include<bits/stdc++.h>
using  namespace  std;

//断言工具函数：如果val为假则输出s然后中断程序
void  Assert(bool  val,string  s){
        if(!val){
                cout<<"断言失败："<<s<<endl;
        }
}

template  <typename  E>  class  List  {  //  List  ADT
private:
        void  operator  =(const  List&)  {}            //  Protect  assignment
        List(const  List&)  {}                      //  Protect  copy  constructor
public:
        List()  {}                    //  Default  constructor
        virtual  ~List()  {}  //  Base  destructor

        //  Clear  contents  from  the  list,  to  make  it  empty.
        virtual  void  clear()  =  0;

        //  Insert  an  element  at  the  current  location.
        //  item:  The  element  to  be  inserted
        virtual  void  insert(const  E&  item)  =  0;

        //  Append  an  element  at  the  end  of  the  list.
        //  item:  The  element  to  be  appended.
        virtual  void  append(const  E&  item)  =  0;

        //  Remove  and  return  the  current  element.
        //  Return:  the  element  that  was  removed.
        virtual  E  remove()  =  0;

        //  Set  the  current  position  to  the  start  of  the  list
        virtual  void  moveToStart()  =  0;

        //  Set  the  current  position  to  the  end  of  the  list
        virtual  void  moveToEnd()  =  0;

        //  Move  the  current  position  one  step  left.  No  change
        //  if  already  at  beginning.
        virtual  void  prev()  =  0;

        //  Move  the  current  position  one  step  right.  No  change
        //  if  already  at  end.
        virtual  void  next()  =  0;

        //  Return:  The  number  of  elements  in  the  list.
        virtual  int  length()  const  =  0;

        //  Return:  The  position  of  the  current  element.
        virtual  int  currPos()  const  =  0;

        //  Set  current  position.
        //  pos:  The  position  to  make  current.
        virtual  void  moveToPos(int  pos)  =  0;

        //  Return:  The  current  element.
        virtual  const  E&  getValue()  const  =  0;
};

//  Singly  linked  list  node
template  <typename  E>  class  Link  {
public:
        E  element;            //  Value  for  this  node
        Link  *next;                //  Pointer  to  next  node  in  list
        //  Constructors
        Link(const  E&  elemval,  Link*  nextval  =NULL)  {
                this->element=elemval;
                this->next=nextval;

        }
        Link(Link*  nextval  =NULL)  {
                this->next=nextval;

        }
};

template  <typename  E>  class  LList:  public  List<E>  {
private:
        Link<E>*  head;              //  Pointer  to  list  header
        Link<E>*  tail;              //  Pointer  to  last  element
        Link<E>*  curr;              //  Access  to  current  element
        int  cnt;                              //  Size  of  list

        void  init()  {                //  Intialization  helper  method
            cnt=0;
            head=new Link<E>();
            curr=head;
            tail=head;       

        }

        void  removeall()  {      //  Return  link  nodes  to  free  store
                // curr=head;
                // while(curr!=tail){
                //         remove();
                // } 
                while(head!=NULL){
                        curr=head;
                        head=head->next;
                        delete curr;
                }

        }

public:
        LList(int  size=100)  {
                init();        //  Constructor
        }
        ~LList()  {
                removeall();        //  Destructor
        }

        //  使用空格分隔输出线性表中的所有数据，并最终换行
        //无数据时直接输出空行
        void  print(){
                Link<E> *temp=head;
                while(temp->next!=NULL){
                        temp=temp->next;
                        cout<<temp->element<<" ";
                }
                cout<<endl;

        }

        void  clear()  {
                removeall();        //  Clear  list
                init();
        }

        //  Insert  "it"  at  current  position
        void  insert(const  E&  it)  {
                curr->next=new Link<E>(it,curr->next);
                if(curr==tail)tail=curr->next;
                cnt++;
        }

        void  append(const  E&  it)  {  //  Append  "it"  to  list
                tail->next=new Link<E>(it);
                tail=tail->next;
                cnt++;
        }

        //  Remove  and  return  current  element
        E  remove()  {
                Assert(curr->next  !=  NULL,  "No  element");  //如当前元素不存在，将直接报错，并终止程序
                E it=curr->next->element;
                Link<E> * item=curr->next;
                if(tail==curr->next)tail=curr;
                curr->next=curr->next->next;
                delete item;
                cnt--;
                return it;

        }

        //  Place  curr  at  list  start
        void  moveToStart()  {
                curr=head;

        }

        //  Place  curr  at  list  end
        void  moveToEnd()  {
                curr=tail;

        }

        //  Move  curr  one  step  left;  no  change  if  already  at  front
        void  prev()  {
                if(curr!=head){
                        Link<E> *temp=head;
                        while((temp->next)!=curr)temp=temp->next;
                        curr=temp;
                }

        }

        //  Move  curr  one  step  right;  no  change  if  already  at  end
        void  next()  {
                if(curr!=tail)
                        curr=curr->next;

        }

        //  Return  length
        int  length()  const    {
                return cnt;

        }

        //  Return  the  position  of  the  current  element
        int  currPos()  const  {
                Link<E> *temp=head;
                int position=0;
                while(temp!=curr){
                        temp=temp->next;
                        position++;
                }
                return position;
        }

        //  Move  down  list  to  "pos"  position
        void  moveToPos(int  pos)  {
                Assert  ((pos>=0)&&(pos<=cnt),  "Position  out  of  range");
                // Link<E> *temp=head;
                // while(pos--){
                //         temp=temp->next;
                // }
                // curr=temp;
                curr=head;
                for(int i=0;i<pos;i++)curr=curr->next;
        }

        //  Return  current  element
        const  E&  getValue()  const  {
                Assert(curr->next  !=  NULL,  "No  value");
                return curr->next->element;

        }
};