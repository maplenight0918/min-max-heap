// 11027224 蔡奇勳 
#include <iostream> // cout, endl
#include <fstream> // open, is_open
#include <vector> // vector
#include <cstdlib> // atoi, system
#include <iomanip> // setw, setprecision
#include <ctime> // clock, CLOCKS_PER_SEC
#include <sstream>
#include <algorithm>
#include <cmath>
#include <string.h>
using namespace std ;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

typedef struct cT{
	
    string cnumber; // college number
    string cname; // college name
    string dnumber; // department number
    string dname; // department name
    string classtime ; // day or night
    string stage ; // in school stage
    string sNO; // number of students
    string tNO; // number of teahers
    string gNO; // number of graduates
    string city; // 縣市名稱 
    string mainly;//體系別數字 
 
} collegeType;

typedef struct hT {
	
	int rid ;  // initial number 
	int value ;
	string cname ;
	string dname ;
	string classtime ;
	string stage ;
	
	
} heapType;

bool detectisDigit( string target ){
	
	for ( int i = 0 ; i < target.size() ; i++ ){      // 看他不是合法輸入(數字部分) 
		if ( !isdigit(target[i]) )
		  return false;    
	}
	
	return true ;  
}

class collegelist{
  vector<collegeType> data ;
  string fileID ;
  heapType temp ;
public:
  heapType pophT(){

  	temp.cname = data[0].cname ; 
  	temp.classtime = data[0].classtime ; 
  	temp.dname = data[0].dname ;
  	temp.stage = data[0].stage ;
  	
  	
  	return temp ;
  }	
  int popgNO(){
  	
  	collegeType temp = data[0] ;
  	int g = atoi(temp.gNO.c_str()) ;
  	data.erase(data.begin()) ;
    return g ;
    
  }	
  
  int getsize(){
  	return data.size();
  }
  bool rdname(){
	
      string number, filename ;
      ifstream in ;
      cin >> number ;
      
      cout << endl ;
	  filename = "input" + number + ".txt" ;

	  in.open(filename.c_str());
			

      while( in.fail() ){
      	
      	if( strcmp( number.c_str(), "0" ) == 0 )
          return false ;
          
        cout << "### input" << number <<".txt does not exist! ###" << endl << endl ;
    
        cout << "Input a file number ([0] Quit): "  ;
        
		cin >> number ; 
		cout << endl ;
		filename = "input" + number + ".txt" ;
		in.open(filename.c_str());		
      }	
		
	  fileID = number ;	
	  
	  in.close();	
	   
	  return true ;	
  } 
  
  void readfile() {
  	
    string number, filename, temp, add ; 
    	
    int count = 0 ;
    	
    filename = "input" + fileID + ".txt" ;
    			
    collegeType buffer ;
    char ch ;
    ifstream in ;   
   
    in.open(filename.c_str()) ;
    
    
    for ( int i = 0 ; i < 3 ; i++ )
    	getline( in, temp ) ; 
    	
    temp.clear() ;
    
    while( !in.eof() ) {
    		
    	if( in.peek() != '\t' ){
    	  while( in.get(ch) && ch != '\t' ){
    	     	
    	    temp += ch ;	
    	    if ( ch == '\n')
    	        break ;
    	         		   	 	
			}
	
		}
    	else{
    	  in.get(ch) ;
    	  temp = ch ;

		} 	
		   
    	if( count == 0 ){
    	    buffer.cnumber = temp ;		
		}
		else if ( count == 1 ){
		   	buffer.cname = temp ;		
		}
		else if ( count == 2 ){
		   	buffer.dnumber = temp ;	
		}
		else if ( count == 3 ){
		   	buffer.dname = temp ;
		}
		else if ( count == 4 ){
		   	buffer.classtime = temp ;
		}
		else if ( count == 5 ){
		   	buffer.stage = temp ;
		}
		else if ( count == 6 ){
		   	buffer.sNO = temp ;
		}
		else if ( count == 7 ){
		   	buffer.tNO = temp ;
		}
		else if ( count == 8 ){
		   	buffer.gNO = temp ;
		}
		else if ( count == 9 ){
		   	buffer.city = temp ;	
		}
		else if ( count == 10 ){
		    buffer.mainly = temp ;
		    data.push_back(buffer);
		}

    	   
    	count++ ;
    	   
    	if( count == 11 )
    	    count = 0 ;
    	    
    	temp = "" ;

        }
	}
	
	void printdata(){
	  string filename ;
	  
	  filename = "input" + fileID + ".txt" ;
	  
	  for( int i = 0 ; i < data.size() ; i++ ){
	  	cout << data[i].cnumber << endl ;
	  }
		
    }
	
	void clearall(){
		data.clear();
	}  	
};

class Minheap{
	
  vector<heapType> heapdata ;
  
public:
    

	void heapdata_p(){

	  
	  for( int i = 0 ; i < heapdata.size() ; i++ ){
	  	cout << heapdata[i].rid << heapdata[i].value << endl ;
	  }
		
    }
			
    void minheap_insert( heapType newdata ){
      
      heapdata.push_back(newdata) ;
	  
	  int bottom = heapdata.size() - 1 ;
	  
	  int parent = (bottom - 1) / 2 ;
	  
	  while ( bottom > 0 && heapdata[parent].value > heapdata[bottom].value ){
	  	
	  	swap( heapdata[parent], heapdata[bottom] ) ;
	  	
	  	bottom = parent ;
	  	
	  	parent = (bottom - 1 ) / 2 ;
	  	
	  } 
	      	
	}
	void mission1_print(){
		
	  if( heapdata.size() == 0 )
	    return ;
	    
	  cout << "<min heap>" <<  endl ;
	   
	  cout << "root: ["	<< heapdata[0].rid << "] " << heapdata[0].value << endl ;
	  
	  cout << "bottom: [" << heapdata[heapdata.size() - 1].rid << "] " << heapdata[heapdata.size() - 1].value << endl ;
	  
	  cout << "leftmost bottom: ["	<< heapdata[get_leftmost()].rid << "] " << heapdata[get_leftmost() ].value << endl ;
	  
	}
	
	int get_leftmost(){
			
		int i = 1 ;
		
		while ( i <= heapdata.size() ){
		  i = i * 2 ;	
		}
		
		if( heapdata.size() == 0)
		  return 0 ;
		else
		  return i / 2 - 1 ;
	}
	
	void clearall(){
		heapdata.clear() ;
	}
};

class Min_maxheap{
	
  vector<heapType> heapdata ;
  
  
public:
	
  int getsize(){
  	  return heapdata.size();
  }		
  vector<heapType> heapdata_catch(){
    	return heapdata ;
  }
  
  void heapdata_p(){
  
	  for( int i = 0 ; i < heapdata.size() ; i++ ){
	  	cout << heapdata[i].rid << heapdata[i].value << endl ;
	  }
		
  }
		
  void minheap( int index ){
  	
  	  if( index <= 2 )
  	    return ;
      
	  int grandparent = ( index - 3) / 4  ;
	  
	  if (heapdata[grandparent].value > heapdata[index].value ){
	  	
	  	swap( heapdata[index], heapdata[grandparent] ) ;
	  	
        minheap(grandparent) ;
	  	
	  }

  }  
  
  void maxheap( int index ){
	  	  
  	  if( index <= 2 )
  	    return ;
      
	  int grandparent = ( index - 3 ) / 4 ;
	  
	  if ( heapdata[grandparent].value < heapdata[index].value ){
	  	
	  	swap( heapdata[index], heapdata[grandparent] ) ;
	  	
        maxheap(grandparent) ;
	  	
	  }
	      	
  }
  
  void mmheap_insert( heapType newdata ){
  	
  	heapdata.push_back(newdata) ;
  	
	int bottom = heapdata.size() - 1 ;
	  
	int parent = (bottom - 1) / 2 ;
	
	int level = getlevel(bottom) ;
	

	if ( bottom <= 0 )
	  return ; 
	
	if( level % 2 == 0 ){
		
		if( heapdata[bottom].value > heapdata[parent].value ){
			
			swap( heapdata[bottom], heapdata[parent] ) ;			
	 		maxheap( parent );
		}
		else
		  minheap(bottom);
	}
	else{
		if( heapdata[bottom].value < heapdata[parent].value ){
			
			swap( heapdata[bottom], heapdata[parent] ) ;				
			minheap( parent );
		}
		else
		  maxheap(bottom);		
	}
  	
  }
  
  int getlevel( int index ){
    return floor(log2(index + 1));	
  }	
  
  int get_leftmost(){
			
		int i = 1 ;
		
		while ( i <= heapdata.size() ){
		  i = i * 2 ;	
		}
		
		if( heapdata.size() == 0)
		  return 0 ;
		else
		  return i / 2 - 1 ;
  }  
  void mission2_print(){
  	
		
	  if( heapdata.size() == 0 )
	    return ;
	    
	  cout << "<min-max heap>" <<  endl ;
	   
	  cout << "root: ["	<< heapdata[0].rid << "] " << heapdata[0].value << endl ;
	  
	  cout << "bottom: [" << heapdata[heapdata.size() - 1].rid << "] " << heapdata[heapdata.size() - 1].value << endl ;
 
	  cout << "leftmost bottom: ["	<< heapdata[get_leftmost()].rid << "] " << heapdata[get_leftmost() ].value << endl ;
	  
  }
  void clearall(){
  	heapdata.clear() ;
  }
  
  void heapdata_print(){

	  
	   for( int i = 0 ; i < heapdata.size() ; i++ ){
	  	cout << " " << heapdata[i].value << endl ;
	  }
		
  }
  
  bool hasLeftChild(int index) {
  	
    int leftc = 2 * index + 1;
    
    if( leftc < heapdata.size() ){
      return true ;
    }
    else{
      return false ;
    }
  }

  bool hasRightChild(int index) {
  	
    int rightc = 2 * index + 2;
    
    if( rightc < heapdata.size() ){
      return true ;
    } 
    else{
      return false ;
    }
  }  
  
  bool hasGrandChild( int left ){
  	
	 if( left * 2 + 1 < heapdata.size()  ) 
	   return true ;
	 else
	   return false ;
  }
  
  int findmingc( int gc1, int gc4 ){
  	
  	int mingc = gc1 ;
  	
  	for( int i = gc1 ; i <= gc4 && i < heapdata.size() ; i++ ) {
  	  if( heapdata[mingc].value > heapdata[i].value )
		mingc = i ;

	}
	
	return mingc ;
  }
  
  
  void printandset( int num ){
  	
  	heapType min ;
  	min = heapdata[0] ;
    swap( heapdata[heapdata.size() - 1], heapdata[0] ) ;    
    heapdata.pop_back() ;
    
    cout << "Top " << right << setw(3) << num <<  ": [" << min.rid << "] " << min.cname << min.dname << ", " << min.classtime << ", " << min.stage << ", " << min.value << endl ; 
    
  }
  void findmink( int current ){
  	  
  	     
		int minGC ;
		 
		int cdl = current * 2 + 1 ;
		int cdr = current * 2 + 2 ; 
		
		int gc1 = cdl * 2 + 1 ;
		int gc2 = cdl * 2 + 2 ;
		int gc3 = cdr * 2 + 1 ;
		int gc4 = cdr * 2 + 2 ;
		
		if( hasLeftChild(current) ){
			
	      if( hasLeftChild(current) && hasRightChild(current)  ){
	      	
	        if( heapdata[cdl].value <= heapdata[cdr].value  ){
	        	
			  if( heapdata[cdl].value < heapdata[current].value )
		        swap(heapdata[current], heapdata[cdl] ) ;
		        
		    }
		    else{
		    	
		      if( heapdata[cdr].value < heapdata[current].value )
		        swap(heapdata[current], heapdata[cdr] ) ; 
		        
		    }
	      }  
	   	  else{
	   	  	
		    if( heapdata[cdl].value < heapdata[current].value )
		      swap(heapdata[current], heapdata[cdl] ) ;		      
		  }	
		  
		  		
	    }
	    else
	      return ;
	      
	    
	    if( hasGrandChild(cdl) ){
	    	
	      minGC = findmingc(gc1,gc4) ;
	      
	      if( heapdata[current].value > heapdata[minGC].value  ){
	      	
	      	swap( heapdata[current], heapdata[minGC] ) ;
	      	  
	      	findmink(minGC) ;
	      	
		  }	
		      	
		}
	    
				
  }

 				  
	
  

};

int main(int argc, char** argv) {
	
	collegelist data ;
	Minheap mheap ;
	Min_maxheap mmheap ;
    int command = 0; // user command
	int count = 1 ;
	
	do{ 
	
		//JobList orders; // a list of orders
 		cout << endl << "********** Heap Construction **********";
 		cout << endl << "* 0. QUIT                             *";
 		cout << endl << "* 1. Build a min heap                 *";
 		cout << endl << "* 2. Build a min-max heap             *";
 		cout << endl << "* 3: Top-K minimums from min-max heap *";
 		cout << endl << "***************************************";
		cout << endl << "Input a choice(0, 1, 2, 3): ";

		
 		cin >> command; // get the command
 		cout << endl  ;
 		
 		switch (command){ 
 		
 		    
			case 0: 
				break;
 			case 1:
 				cout << "Input a file number ([0] Quit): "  ;
 				
 				if( data.rdname() ){
 				 
			      data.readfile();	
			      
			      while( data.getsize() != 0 ){
			      	heapType temp = data.pophT() ;
			      	temp.value = data.popgNO() ;
			      	temp.rid = count ;
			      	mheap.minheap_insert(temp) ;
			      	count ++ ;
				  }
                  
                 
                  mheap.mission1_print() ;
                  
				}
				
				mheap.clearall();
				data.clearall();
				count = 1 ;
 				break;
 				
 			case 2: 
 		     	cout << "Input a file number ([0] Quit): "  ;
 		     	
 		     	
 				if( data.rdname() ){
 					
 				  mmheap.clearall();		
			      data.readfile();	

			      while( data.getsize() != 0 ){
			      	heapType temp ;
			      	temp = data.pophT() ;
			      	temp.value = data.popgNO() ;
			      	temp.rid = count ;

			      	mmheap.mmheap_insert(temp) ;
			      	count ++ ;
				  }
                  
                 
                  mmheap.mission2_print() ;
				}
				
				data.clearall();				
				count = 1 ;
 				break;
 				
 			case 3: {
 				
 			  if( mmheap.getsize() == 0)
 			    break ;
				  
 			  string numberk ;
 			  cout << "Enter the value of K in [1,"<< mmheap.getsize() << "]: " ;
              cin >> numberk ;
              
              while( !detectisDigit(numberk) || atoi(numberk.c_str()) > mmheap.getsize() ){
              	
              	cout << "### Wrong Type of input ###" << endl << endl ;
              	
              	cout <<"Enter the value of K in [1," << mmheap.getsize() << "]: " ;
              	
              	cin >> numberk ;
              	
			  }
              
                  
              for( int i = 0 ; i < atoi(numberk.c_str()) ; i++){
              	mmheap.printandset(i+1) ;
			    mmheap.findmink(0) ;
			    
			  }
		      
		    }
		    break ;	 
			   
 			default:  cout << endl << "Command does not exist!" << endl;
 			

 		} // end switch
 	} while (command != 0);
	 	
	return 0;
}
