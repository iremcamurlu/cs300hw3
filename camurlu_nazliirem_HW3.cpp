#include <iostream>
#include <string>
#include <time.h>
#include <conio.h>
#include<fstream>
#include<vector>
#include <ctime>
#include <chrono>
#include <iomanip>
#include <time.h> 
#include <sstream>

//NAZLI IREM CAMURLU HW3
using namespace std;
string file_nammee;
struct DocumentItem//struct to store the document name and count of each file
{
	string documentName;
	int count;
};
struct WordItem //struct to store the words and their document names and counts
{
	string word;
	DocumentItem worder1;//document items put into the struct to store the document name and count info of each word
	DocumentItem worder2;
	DocumentItem worder3;
	DocumentItem worder4;
	DocumentItem worder5;
	DocumentItem worder6;
};
struct Node 
{
WordItem elem;
Node *left;
Node *right;
//int height;
 };
template <class HashedObj>
        class HashTable
        {
          public:
            explicit HashTable( const HashedObj & notFound, int size = 53 );
            HashTable( const string & rhs )
                   : ITEM_NOT_FOUND( rhs.ITEM_NOT_FOUND ),
                     array( rhs.array ), currentSize( rhs.currentSize ) { }

            HashedObj & find( const HashedObj & x ) ;
			bool finder_query(const string &x,string new_filename_new);//boolean that returns true if the given query is found
			void new_found(const string &x,string new_filename_new);//if the query is found in the document function prompts the word and the number of occurences
            void makeEmpty( );
			int getSize();
			void insert_hash(const HashedObj&x,WordItem*&temp);//insert hash function that inserts the elements to the hash table when it is rehashed.
			double get_load_factor();//load factor that determines whether the hash table should be rehashed
            void insert(  const HashedObj & x);//insert function that inserts elements to the hash table in the beginning 
			void remove( const HashedObj & x );//hash remove function

            const HashTable & operator=( const HashTable & rhs );

            enum EntryType { ACTIVE, EMPTY, DELETED };
private:
    struct HashEntry//hashentry struct to store the hash elements 
    {
         WordItem element;
         EntryType info;
		 HashEntry( const WordItem & e = WordItem( ), 
					EntryType i = EMPTY )
					: element( e ), info( i ) { }
    };     

    std::vector<HashEntry> array;//array that is made with hashentry struct
    int currentSize;
    HashedObj ITEM_NOT_FOUND;

    bool isActive( int currentPos ) const;
    int findPos( const HashedObj & x ) const;//function that returns the position of the given hash element
    void rehash();//rehash function
	
 };
int ha_sh( const string & key, int tableSize );//hash function that finds a position in the table

 bool isPrime( int n )//prime number function to check if the number is prime
  {
            if( n == 2 || n == 3 )
                return true;

            if( n == 1 || n % 2 == 0 )
                return false;

            for( int i = 3; i * i <= n; i += 2 )
                if( n % i == 0 )
                    return false;

            return true;
  }

 int nextPrime( int n )//function that returns the next prime from the given integer
        {
            if( n % 2 == 0 )
                n++;

            for( ; !isPrime( n ); n += 2 )
                ;

            return n;
        }

        /**
         * Construct the hash table.
         */
			
        template <class HashedObj>
        HashTable<HashedObj>::HashTable( const HashedObj & notFound, int size )
          : ITEM_NOT_FOUND( notFound ), array( nextPrime( size ) )//constructor
        {
            makeEmpty( );
        }


		
		template <class HashedObj>void HashTable<HashedObj>::new_found(const string &x,string new_filename_new)//function that prompts the found queries if found
		{
			WordItem a;
			a.word=x;
			WordItem *temp = &find(a);
			if(temp->worder1.documentName==new_filename_new)
			{
			cout<<"In document "<<new_filename_new<<" "<<x<<" found "<<temp->worder1.count<<" times."<<endl;
			}
			else if(temp->worder2.documentName==new_filename_new)
			{
			cout<<"In document "<<new_filename_new<<" "<<x<<" found "<<temp->worder2.count<<" times."<<endl;
			}
			else if(temp->worder3.documentName==new_filename_new)
			{
			cout<<"In document "<<new_filename_new<<" "<<x<<" found "<<temp->worder3.count<<" times."<<endl;
			}
			else if(temp->worder4.documentName==new_filename_new)
			{
			cout<<"In document "<<new_filename_new<<" "<<x<<" found "<<temp->worder4.count<<" times."<<endl;
			}
			else if(temp->worder5.documentName==new_filename_new)
			{
			cout<<"In document "<<new_filename_new<<" "<<x<<" found "<<temp->worder5.count<<" times."<<endl;
			}
			else if(temp->worder6.documentName==new_filename_new)
			{
			cout<<"In document "<<new_filename_new<<" "<<x<<" found "<<temp->worder6.count<<" times."<<endl;
			}

		}

		template<class HashedObj>bool HashTable<HashedObj>::finder_query(const string &word,string new_filename_new)
		{//finder query function that returns true if the element is present in the hash table.
			WordItem a;
			a.word=word;
			WordItem *temp=&find(a);
			if (temp->word == word)	
			{
				if(temp->worder1.count>0)
				{
					if(temp->worder1.documentName==new_filename_new)
					{
						return true;
					}

				}
				if(temp->worder2.count>0)
				{
					if(temp->worder2.documentName==new_filename_new)
					{
						return true;
					}

				}
				if(temp->worder3.count>0)
				{
					if(temp->worder3.documentName==new_filename_new)
					{
						return true;
					}

				}
				if(temp->worder4.count>0)
				{
					if(temp->worder4.documentName==new_filename_new)
					{
						return true;
					}

				}
				if(temp->worder5.count>0)
				{
					if(temp->worder5.documentName==new_filename_new)
					{
						return true;
					}

				}
				if(temp->worder6.count>0)
				{
					if(temp->worder6.documentName==new_filename_new)
					{
						return true;
					}

				}
			}
			
				return false;
		}
		template <class HashedObj>void HashTable<HashedObj>::insert_hash(const HashedObj&x,WordItem*&temp)
		{//this function is used to insert the elements when the table is rehashed and we dont want to lose the previous information of elements.
			temp->worder1.count=x.worder1.count;//copy all the previous info with the help of the temp pointer
			temp->worder2.count=x.worder2.count;
			temp->worder3.count=x.worder3.count;
			temp->worder4.count=x.worder4.count;
			temp->worder5.count=x.worder5.count;
			temp->worder6.count=x.worder6.count;
			temp->worder1.documentName=x.worder1.documentName;
			temp->worder2.documentName=x.worder2.documentName;
			temp->worder3.documentName=x.worder3.documentName;
			temp->worder4.documentName=x.worder4.documentName;
			temp->worder5.documentName=x.worder5.documentName;
			temp->worder6.documentName=x.worder6.documentName;
			int currentPos=findPos(x);
			if(isActive(currentPos))
			{
				return;
			}
			if( array[ currentPos ].info != DELETED )
                ++currentSize;
			//temp=&array[currentPos].element;
			array[ currentPos ] = HashEntry( x, ACTIVE );
		    
            if( ((((array.size())/(currentSize))<0.25)||(((array.size())/(currentSize))>0.9))&&(currentSize > array.size( ) / 1.2 ))
                rehash( );

		}

        template <class HashedObj>
        void HashTable<HashedObj>::insert( const HashedObj &x)//insert function that finds a place for the given word
        {
			WordItem*temp;
            int currentPos = findPos( x );
			
            if( isActive( currentPos ) )
			{
				temp=&find(x);//temp pointer that points to the word item x.

			if(temp->worder1.documentName==file_nammee)//update info using the pointer
			{
					temp->worder1.count++;	
			}
			else if(temp->worder2.documentName==""||temp->worder2.documentName==file_nammee)
			{
					temp->worder2.documentName=file_nammee;
					if(temp->worder2.count<0)
					temp->worder2.count=1;
					else
						temp->worder2.count++;
			}
			else if(temp->worder3.documentName==file_nammee||temp->worder3.documentName=="")
			{
					temp->worder3.documentName=file_nammee;
					if(temp->worder3.count<0)
					temp->worder3.count=1;
					else
						temp->worder3.count++;
			}
			else if(temp->worder4.documentName==file_nammee||temp->worder4.documentName=="")
			{
					temp->worder4.documentName=file_nammee;
					if(temp->worder4.count<0)
					temp->worder4.count=1;
					else
						temp->worder4.count++;
			}
			else if(temp->worder5.documentName==file_nammee||temp->worder5.documentName=="")
			{
					temp->worder5.documentName=file_nammee;
					if(temp->worder5.count<0)
					temp->worder5.count=1;
					else
						temp->worder5.count++;
			}
			else if(temp->worder6.documentName==file_nammee||temp->worder6.documentName=="")
			{
					temp->worder6.documentName=file_nammee;
					if(temp->worder6.count<0)
					temp->worder6.count=1;
					else
						temp->worder6.count++;
			}
                return;
			}
            if( array[ currentPos ].info != DELETED )//if our element is not present in our array find a position and insert to the array.
                ++currentSize;
			temp=&array[currentPos].element;
			array[ currentPos ] = HashEntry( x, ACTIVE );
			if(temp->worder1.documentName=="")//we update the info of our hashentry element using temp pointer
			{
			temp->worder1.documentName=file_nammee;
			temp->worder1.count=1;
			}
			else if(temp->worder1.documentName!=""&&temp->worder2.documentName=="")
			{
			temp->worder2.documentName=file_nammee;
			temp->worder2.count=1;
			}
			else if(temp->worder1.documentName!=""&&temp->worder2.documentName!=""&&temp->worder3.documentName=="")
			{
				temp->worder3.documentName=file_nammee;
				temp->worder3.count=1;
			}
			else if(temp->worder1.documentName!=""&&temp->worder2.documentName!=""&&temp->worder3.documentName!=""&&temp->worder4.documentName=="")
			{
				temp->worder4.documentName=file_nammee;
				temp->worder4.count=1;
			}
			else if(temp->worder1.documentName!=""&&temp->worder2.documentName!=""&&temp->worder3.documentName!=""&&temp->worder4.documentName!=""&&temp->worder5.documentName=="")
			{
				temp->worder5.documentName=file_nammee;
				temp->worder5.count=1;
			}
			else if(temp->worder1.documentName!=""&&temp->worder2.documentName!=""&&temp->worder3.documentName!=""&&temp->worder4.documentName!=""&&temp->worder5.documentName!=""&&temp->worder6.documentName=="")
			{
				temp->worder6.documentName=file_nammee;
				temp->worder6.count=1;
			}
            
			
                
            if( ((((array.size())/(currentSize))<0.25)||(((array.size())/(currentSize))>0.9))&&(currentSize > array.size( ) / 1.2 ))
                rehash( );//if needed rehash
        }

        /**
         * Expand the hash table.
         */
        template <class HashedObj>
        void HashTable<HashedObj>::rehash( )//rehash function that updates the size of the hash table
        {
			cout<<"rehashed..."<<endl;
			
            vector<HashEntry> oldArray = array;
			cout<<"previous table size: "<<oldArray.size();

                // Create new double-sized, empty table
            array.resize( nextPrime( 2 * oldArray.size( ) ) );
            for( int j = 0; j < array.size( ); j++ )
                array[ j ].info = EMPTY;
			
                // Copy table over
            currentSize = 0;
            for( int i = 0; i < oldArray.size( ); i++ )
                if( oldArray[ i ].info == ACTIVE )
				{
					WordItem*temp;
					temp=&oldArray[i].element;
                    insert_hash( oldArray[ i ].element,temp);
				}
			double loadfac_;
			double len_arr=array.size();
			double curr_size=currentSize;
			loadfac_=curr_size/len_arr;
			cout<<"new table size: "<<array.size();
			cout<<"current unique word count: "<<currentSize;
			cout<<"current load factor: "<<endl;
			cout<<loadfac_;

        }

        /**
         * Method that performs quadratic probing resolution.
         * Return the position where the search for x terminates.
         */
        template <class HashedObj>
        int HashTable<HashedObj>::findPos( const HashedObj & x ) const
        {
	      int collisionNum = 0;
			string a = x.word;
		 int currentPos = ha_sh( a, array.size( ) );

		  while( array[ currentPos ].info != EMPTY &&
                   array[ currentPos ].element.word != x.word )
            {
			  currentPos += 2 * ++collisionNum - 1;  // Compute ith probe
			  if( currentPos >= (array.size()) )
				  currentPos -= (array.size());
			 }

		   return currentPos;
        }


        /**
         * Remove item x from the hash table.
         */
        template <class HashedObj>
        void HashTable<HashedObj>::remove( const HashedObj & x )
        {
            int currentPos = findPos( x );
            if( isActive( currentPos ) )
                array[ currentPos ].info = DELETED;
        }

        /**
         * Find item x in the hash table.
         * Return the matching item or ITEM_NOT_FOUND if not found
         */
        template <class HashedObj>
        HashedObj & HashTable<HashedObj>::find(const  HashedObj & x )
        {
            int currentPos = findPos( x );
            if( isActive( currentPos ) )
                return array[ currentPos ].element;
            else
                return ITEM_NOT_FOUND;
        }
	
        /**
         * Make the hash table logically empty.
         */
        template <class HashedObj>
        void HashTable<HashedObj>::makeEmpty()
        {
            currentSize = 0;
			int len = array.size();
            for( int i = 0; i < len; i++ )
                array[ i ].info = EMPTY;
        }

        /**
         * Deep copy.
         */
        template <class HashedObj>
        const HashTable<HashedObj> & HashTable<HashedObj>::
        operator=( const HashTable<HashedObj> & rhs )
        {
            if( this != &rhs )
            {
                array = rhs.array;
                currentSize = rhs.currentSize;
            }
            return *this;
        }


        /**
         * Return true if currentPos exists and is active.
         */
        template <class HashedObj>
        bool HashTable<HashedObj>::isActive( int currentPos ) const
        {
            return array[ currentPos ].info == ACTIVE;
        }

        /**
         * A hash routine for string objects.
         */
		 template <class HashedObj>
        int HashTable<HashedObj>::getSize()
		{
			return currentSize;
		}
		 template <class HashedObj>
        double HashTable<HashedObj>::get_load_factor()
		{
			double loadfac_;
			double len_arr=array.size();
			double curr_size=currentSize;
			loadfac_=curr_size/len_arr;
			return loadfac_;
		}

        int ha_sh( const string & key, int tableSize )//hash function that find a value for our word
        {
            int hashVal = 0;
			int len = key.length();
            for( int i = 0; i < len; i++ )
                hashVal = 37 * hashVal + key[ i ];

            hashVal %= tableSize;
            if( hashVal < 0 )
                hashVal += tableSize;

            return hashVal;
        }

template <class Key>
class BST {
    

Node* root;
bool unique_finder(const string &x)
{

	root_x=find(x,root);//node is found
	
}

Node * find( const string & x,Node *t)const//find function to find the searched query
	{
		if ( t == NULL )

			return NULL;

		else if( x < t->elem.word )//if the element searched is smaller alphabetically recursively go to left

			return find( x, t->left );

		else if( t->elem.word < x )//if the element searched is bigger alphabetically recursively go to right

			return find( x, t->right );

		else

			return t ; //if found return
	}

void insert( const string & x,const string & y,Node *&t)//insert function to insert the new words in the tree
{
		
	if(t==NULL)//if the word havent been found in the tree than initialize a new node
	{
		int a =0;
		t = new Node;
		t->elem.word=x;
		t->elem.worder1.documentName=y;
		//t->height=0;
		t->left=NULL;
		t->right=NULL;
		t->elem.worder1.count=1;
	}
	
	
	else if(x==t->elem.word)//if the element is found before than initialize new document item or if the document name is the same than increase the counter
	{
			if(t->elem.worder1.documentName==y)
			{
			
			t->elem.worder1.count++;
			}
			else if(t->elem.worder2.documentName==y)
			{
				t->elem.worder2.count++;
			}
			else if(t->elem.worder3.documentName==y)
			{
				t->elem.worder3.count++;
			}
			else if(t->elem.worder4.documentName==y)
			{
				t->elem.worder4.count++;
			}
			else if(t->elem.worder5.documentName==y)
			{
				t->elem.worder5.count++;
			}
			else if(t->elem.worder6.documentName==y)
			{
				t->elem.worder6.count++;
			}
			else if(t->elem.worder2.documentName=="")
			{
				t->elem.worder2.documentName=y;
				t->elem.worder2.count=1;
			}
			else if(t->elem.worder3.documentName=="")
			{
				t->elem.worder3.documentName=y;
				t->elem.worder3.count=1;
			}
			else if(t->elem.worder4.documentName=="")
			{
				t->elem.worder4.documentName=y;
				t->elem.worder4.count=1;
			}
			else if(t->elem.worder5.documentName=="")
			{
				t->elem.worder5.documentName=y;
				t->elem.worder5.count=1;
			}
			else if(t->elem.worder6.documentName=="")
			{
				t->elem.worder6.documentName=y;
				t->elem.worder6.count=1;
			}


		
	}
	else if (x<t->elem.word)//if the word searched for is smaller alphabetically go to left recursively
	{
		insert(x,y,t->left);
		

	}
	else if(x>t->elem.word)////if the word searched for is bigger alphabetically go to right recursively
	{
		insert(x,y,t->right);
	

	}
	
	//balance(t);//balance the tree
}
Node * clone( Node *t ) const//copy constructor function to clone the avltree if needed
{
if( t == nullptr )
return nullptr;
else
return new Node{ t->elem, clone( t->left ), clone( t->right )};
}
void makeEmpty(Node* t)//to destruct the tree recursively right and left trees are destructed
{
       if(t == NULL)
            return;
        makeEmpty(t->left);
        makeEmpty(t->right);
        delete t;
}

Node* findMin(Node* t)
 {
        if(t == NULL)
            return NULL;
        else if(t->left == NULL)
            return t;
        else
            return findMin(t->left);
 }

 Node* findMax(Node* t) 
{
if(t == NULL)
	return NULL;
else if(t->right == NULL)
	return t;
else
	return findMax(t->right);
 }



public:
    BST() {
        root = NULL;
    }

    ~BST() {
        makeEmpty(root);
    }
	BST(const BST&rhs)//copy constructor
	{
		root = clone( rhs.root );
	}


    void insert_tree(Key x,Key y)//insert function
	{

		insert(x,y,root);
	}
	
	void newly_found(Key x,string new_filename_new)//function that prompts the found query word document name and count
	{
			Node*root_x;
			root_x=find(x,root);
			if(root_x->elem.worder1.documentName==new_filename_new&&root_x->elem.word==x)
			{
			cout<<"In document "<<new_filename_new<<" "<<x<<" found "<<root_x->elem.worder1.count<<" times"<<endl;
			}
			if(root_x->elem.word==x&&root_x->elem.worder2.documentName==new_filename_new)
			{
			cout<<"In document "<<new_filename_new<<" "<<x<<" found "<<root_x->elem.worder2.count<<" times"<<endl;
			}
			if(root_x->elem.word==x&&root_x->elem.worder3.documentName==new_filename_new)
			{
			cout<<"In document "<<new_filename_new<<" "<<x<<" found "<<root_x->elem.worder3.count<<" times"<<endl;
			}
			if(root_x->elem.word==x&&root_x->elem.worder4.documentName==new_filename_new)
			{
			cout<<"In document "<<new_filename_new<<" "<<x<<" found "<<root_x->elem.worder4.count<<" times"<<endl;
			}
			if(root_x->elem.word==x&&root_x->elem.worder5.documentName==new_filename_new)
			{
			cout<<"In document "<<new_filename_new<<" "<<x<<" found "<<root_x->elem.worder5.count<<" times"<<endl;
			}
			if(root_x->elem.word==x&&root_x->elem.worder6.documentName==new_filename_new)
			{
			cout<<"In document "<<new_filename_new<<" "<<x<<" found "<<root_x->elem.worder6.count<<" times"<<endl;
			}
	}


	bool finder(Key x,string new_file_name,int count_num)//public find function to reach to find function in private
	{
			Node*root_x;
			int count=0;
			root_x=find(x,root);//node is found
			if(root_x!=NULL)//if it is not NULL then cout the document names and counts of the searched word
			{
				if(root_x->elem.worder1.count>0&&root_x->elem.worder1.documentName==new_file_name)
				{
					
						return true;
			
				}

				
				if(root_x->elem.worder2.count>0&&root_x->elem.worder2.documentName==new_file_name)
				{
					
						return true;

				}
				if(root_x->elem.worder3.count>0&&root_x->elem.worder3.documentName==new_file_name)
				{
					
						return true;
			

				}

				if(root_x->elem.worder4.count>0&&root_x->elem.worder4.documentName==new_file_name)
				{
					
						return true;

				}

			if(root_x->elem.worder5.count>0&&root_x->elem.worder5.documentName==new_file_name)
				{
					
						return true;
					
				}
			if(root_x->elem.worder6.count>0&&root_x->elem.worder6.documentName==new_file_name)
				{
						return true;
					

				}
		}
			else if(root_x==NULL){
			return false;
			}

	}


  void search(int x) {
        root = find(root, x);
    }
};


string checkcharacter(string &word)//character check function to make sure all the characters are lowercase.
{
		int len = word.length();
		for(int i=0 ;i<len;i++){
			
		if (word[i] <= 'Z' && word[i] >= 'A')
		{
        word[i]= word[i] + 32;
		}
		else if (word[i]<='z'&&word[i]>='a')
		{
			word[i]=word[i];
		}


		else 
		{
		word[i]=' ';
		break;
		}

	
			}
		
		
return word;
}

int main()
{
	
	WordItem elemento;
	int size = 53;
	bool returner=false;
	bool returned=false;
	BST<string> myTree;
	HashTable <WordItem> hashmap(elemento,size);//hashmap initialized
	ifstream input;
	vector<string>query;//string vector that will store the query words if found for the bst tree
	vector<string>query_2;//string vector that will store the query words if found for the hashtable
	vector<int>counts;
	ofstream offstreamer;
	string line;
	vector<string>files;//string vector that stores the names of the files
	WordItem new_word;//word item initialized to be used to convert the string into word item when inserting to hashmap
	int noter=0;
	string word;
	int count_1=0;//count numbers to be ableto update the file names when needed
	int count_2=0;
	int count_3=0;
	int count_4=0;
	int count_5=0;
	int count_6=0;
	string query_word;
	string file_name2;
	int num_files;
	string file_name;
	cout<<"Enter number of input files: ";
	cin>>num_files;
	file_name2="new_file.txt";
	offstreamer.open(file_name2);
	int file_number =0;
	for(file_number;file_number<num_files;file_number++)//continue until all the file information is inserted into the tree.
	{
		//noter++;
		cout<<"Enter "<<file_number+1<<". file name: ";
		cin>>file_name;
		files.push_back(file_name);
		input.open(file_name.c_str());
	
		while(getline(input,line))
		{
			
			istringstream stringStream(line);
			while(stringStream>>word)//while we get the input from the file is  inserted to the tree
			{
				int len = word.length();
				for(int i=0 ;i<len;i++)
				{
					if(!((word[i] <= 'Z' && word[i] >= 'A')||(word[i]<='z'&&word[i]>='a')))
					{
						word[i]=' ';
						
					}

				}
				if(file_number==0)//if file number is 0 then there are count number of elements in that file same for all the counts to be able to divide  the number of words in each file.
				{
					count_1++;
				}
				if(file_number==1)
				{
					count_2++;
				}
				if(file_number==2)
				{
					count_3++;
				}
				if(file_number==3)
				{
					count_4++;
				}
				if(file_number==4)
				{
					count_5++;
				}
				if(file_number==5)
				{
					count_6++;
				}
				offstreamer<<word;
				offstreamer<<'\n';
				

			}
			
		}
		
	
		input.close();
	}
	
	
		offstreamer.close();
		counts.push_back(count_1);
		counts.push_back(count_2);
		counts.push_back(count_3);
		counts.push_back(count_4);
		counts.push_back(count_5);
		counts.push_back(count_6);
		input.open(file_name2.c_str());
		int new_counter=0;
		::file_nammee=files[0];
		file_name = files[0];
		while(getline(input,line))
		{
		
		if(new_counter>counts[0]&&new_counter<counts[0]+counts[1])//if number of words exceed the number of words in the document update the filename
		{
			::file_nammee=files[1];//global filename that is updated globally if needed.
			file_name = files[1];
		}
		else if(new_counter>counts[1]&&new_counter>counts[0]+counts[1]&&new_counter<counts[0]+counts[1]+counts[2])
		{////if number of words exceed the number of words in the document update the filename
			::file_nammee=files[2];
			file_name = files[2];
		}
		else if (new_counter>counts[0]+counts[1]+counts[2]&&new_counter<counts[0]+counts[1]+counts[2]+counts[3])
		{////if number of words exceed the number of words in the document update the filename
			::file_nammee=files[3];
			file_name = files[3];
		}
		else if (new_counter>counts[0]+counts[1]+counts[2]+counts[3]&&new_counter<counts[0]+counts[1]+counts[2]+counts[3]+counts[4])
		{////if number of words exceed the number of words in the document update the filename
			::file_nammee=files[4];
			file_name = files[4];
		}
		else if (new_counter>counts[0]+counts[1]+counts[2]+counts[3]+counts[4]&&new_counter<counts[0]+counts[1]+counts[2]+counts[3]+counts[4]+counts[5])
		{////if number of words exceed the number of words in the document update the filename
			::file_nammee=files[5];
			file_name = files[5];
		}
	
		istringstream stringStream(line);
		while(stringStream>>word)
		{
		word = checkcharacter(word);//check the character and return it as lowercase
	

		myTree.insert_tree(word,file_name);//insert the tree our word
		
		WordItem new_element;//worditem to convert our word to worditem to be able to insert into hashmap
		new_element.word=word;
		hashmap.insert(new_element);
		new_counter++;//new counter increased to be able to see if the word belongs to which file
		}
		}
		input.close();
		cout<<'\n';
		cout<<"After preprocessing , the unique word count is "<<hashmap.getSize()<<". Current load ratio is "<<hashmap.get_load_factor()<<endl;
		string file_name3;
		int count_num=0;
		file_name3="new_file_new.txt";
		string keyword;
		offstreamer.open(file_name3);
		bool getliene=false;
		cin.ignore();
		cout<<"Enter queried words in one line :";//getting query word from the user
		while(getline(cin,keyword))
		{
		istringstream stream(keyword);
		string tempword;
		while(stream>>tempword)
		{
		int len = tempword.length();
		for(int i=0 ;i<len;i++)//separates the words if it contains any other character other than alphabetical ones
				{
					if(!((tempword[i] <= 'Z' && tempword[i] >= 'A')||(tempword[i]<='z'&&tempword[i]>='a')))
					{
						tempword[i]=' ';
						
					}

				}
		count_num++;
		offstreamer<<tempword;
		offstreamer<<' ';
		}
		break;
		}
		//getliene=true;
		offstreamer.close();
		
		bool found1;//true if the string is found
		bool found2;
		int just_counter=0;
		int new_counter_2=0;
			int k = 20;
			
	auto start = std::chrono::high_resolution_clock::now();
	double Bst;
	int count_query=0;
	for(int x=0;x<files.size();x++)
	{
		input.open(file_name3.c_str());
		string new_file_name= files[x];
		while(getline(input,line))
		{
			
			istringstream stream(line);
			while(stream>>query_word)
			{
				count_query++;//increases every time there is a new word to be able to see if the document contains all the words later.
				checkcharacter(query_word);
					
	for (int i = 0; i < k; i++)
	{
		found2 = myTree.finder(query_word,new_file_name,count_num);//return true if found in the true
		// QueryDocuments(with BST);
	
	}
		if(found2)//if found increase the counter
		{
		just_counter++;
		query.push_back(query_word);//push back the query word for later use
		}

		
			}

	
	}
		input.close();
		if(just_counter==count_query)//if found word counter is equal to number of words entered display the words
		{
			for(int t=0;t<query.size();t++)
			{
				string query_go=query[t];
			myTree.newly_found(query_go,new_file_name);
			}
			returned=true;
		}
		
		
}
	if(!returned)//if no document contains the word display not found
		{
			cout<<"No document contains given query"<<endl;
		}
auto BSTTime = std::chrono::duration_cast<std::chrono::nanoseconds> 
(std::chrono::high_resolution_clock::now() - start);
	cout << "\nTime: " << BSTTime.count() / k << "\n";
	Bst=BSTTime.count();
		start = std::chrono::high_resolution_clock::now();
		int count_query_2=0;
	for(int i =0;i<files.size();i++)
{ 
		input.open(file_name3.c_str());
		string new_file_name= files[i];
		istringstream stream(line);
			while(getline(input,line))
		{
			while(stream>>query_word)
			{
				count_query_2++;////increases every time there is a new word to be able to see if the document contains all the words later.
				checkcharacter(query_word);
	for (int i = 0; i < k; i++)
	{
		// QueryDocuments (with hashtable);
		found1 = hashmap.finder_query(query_word,new_file_name);//return true if the word is found
		
	}
	if(found1)
		{
			new_counter_2++;//increase the counter every time it is found
			query_2.push_back(query_word);//push back the found query word for later use
		}
			}
		}
	input.close();
	if(new_counter_2==count_query_2)//if number of entered words is equal to found words in the document  display the occurences and words
	{
		for(int f=0;f<query_2.size();f++)
		{
			string quer_go;
			quer_go=query_2[f];
		hashmap.new_found(quer_go,new_file_name);
		returner = true;
		}

	}
}
	
if(!returner)//if no document contains the given word display not found
	{
		cout<<"No document contains given query"<<endl;
	}
auto HTTime = std::chrono::duration_cast<std::chrono::nanoseconds> 
(std::chrono::high_resolution_clock::now() - start);
	cout << "\nTime: " << HTTime.count() / k << "\n";
	double speed_up;
	speed_up=Bst/HTTime.count();
	cout<<"Speed up:"<<speed_up;
	cin.get();
	cin.ignore();
	return 0;
}
