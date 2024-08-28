/**
* @file
* @brief Arbol binario de busqueda
* @author Nicolle Montaño
* @copyright MIT license
*/

#ifndef BINARIO_H
#define BINARIO_H
using std::cout;
using std::endl;
namespace arbol{
	template <class T>
	
	/**
	* @brief Arbol binario de busqueda
	*/	
	class binario{
	private:
		
		/**
		* @brief Nodo binario 
		*/
		struct nodo{
			T dato; /*!< Dato alamcenado*/
			nodo * izq; /*!< Referencia al hijo izquierdo*/
			nodo * der;/*!< Referencia al hijo derecho*/
			
			nodo(T dato):dato(dato),izq(nullptr),der(nullptr){
				
			}
		
		};
		nodo * raiz=nullptr;
		
		/**
		* @brief Recorrido Preorden a partir de n (n-> dato,n->izq,n->der)
		* @param n Nodo de inicio del recorrido
		*/	
		void preorden(nodo * n){
			if (n ==nullptr){
				return;
			}
			cout<<" "<<n->dato;
			//invocar recursivamente el preorden de los hijos
			preorden(n->izq);
			preorden(n->der);
		}
		
		/**
		* @brief Recorrido inorden a partir de n (n->izq,n-> dato,n->der)
		* @param n Nodo de inicio del recorrido
		*/	
		void inorden(nodo * n){
			if (n ==nullptr){
				return;
			}
			inorden(n->izq);
			cout<<" "<<n->dato;
			//invocar recursivamente el inorden de los hijos
			inorden(n->der);
		}
			
		/**
		* @brief Recorrido posorden a partir de n (n->izq,n->der,n-> dato)
		* @param n Nodo de inicio del recorrido
		*/	
		void posorden(nodo * n){
			if (n ==nullptr){
				return;
			}
			posorden(n->izq);
			posorden(n->der);
			cout<<" "<<n->dato;
			//invocar recursivamente el posorden de los hijos
	
		}
				
		/**
		* @brief Intenta insertar un nuevo dato a partir de padre
		* @param padre Potencial padre del nodo
		* @param n Nuevo nodo
		* @return true si n nodo pudo ser insertado	
		*/	
		bool insertar(nodo * padre,nodo * n){
		//verificar si el dato ya esta en el arbol
		if(padre->dato==n->dato){
		
			return false;
		}	
			
		//tratar de insertar en los hijos
		
		if(padre->dato>n->dato){
			//insertar a la izquierda
			if(padre->izq==nullptr){
				//el nuevo nodo de convierte en el hijo izquierdo
				padre->izq=n;
				return true;
			}else{
				return insertar(padre->izq,n);
			}
		}else{
			//insertar a la derecha
			if(padre->der==nullptr){
				padre->der=n;
				return true;
			}else{
				return insertar(padre->der,n);
			}
		}
		}
		
	public:
		
		/**
		* @brief Permie verificar si el arbol esta vacio
		* @return true si el arbol esta vacio
		*/
		bool es_vacio(){
			return(raiz== nullptr);
		}
			
		/**
		* @brief Inserta un nuevo dato en el arbol
		* @param dato Nuevo dato a insertar
		*/		
		void insertar(T dato){
			cout<< "Insertar  "<<dato<<endl;
			nodo * n =new nodo(dato);
			if(es_vacio()){
				raiz=n;
			}else{ 
			
			//Liberar la memoria del nodo si no se pudo insertar
			if (!insertar(raiz,n)){
				delete n;
			}
		}
		}
		/**
		* @brief Imprime e recorrido en preOrden (dato,izq,der)
		*/
		void preorden(){
			preorden(raiz);
			
		}
			/**
			* @brief Imprime e recorrido en preOrden (dato,izq,der)
			*/
			void inorden(){
				inorden(raiz);
				
			}
		/**
		* @brief Imprime e recorrido en inOrden (dato,izq,der)
		*/
		void posorden(){
			posorden(raiz);
			
		}
			
	};

};
#endif
