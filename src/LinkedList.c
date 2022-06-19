#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/LinkedList.h"

static Node* getNode(LinkedList *this, int nodeIndex);

static int addNode(LinkedList *this, int nodeIndex, void *pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void) {
	LinkedList *this;
	this = (LinkedList*) malloc(sizeof(LinkedList));
	if (this != NULL) {
		this->size = 0;
		this->pFirstNode = NULL;
	}
	return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList *this) {
	int returnAux = -1;
	if (this != NULL) {
		returnAux = this->size;
	}

	return returnAux;
}

/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
 (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList *this, int nodeIndex) {

	Node *indicador=NULL;
	int longitud;
	int i;

	if (this != NULL) {
		longitud = ll_len(this);
		if (nodeIndex >= 0 && nodeIndex < longitud) {
			indicador = this->pFirstNode;
			if (nodeIndex != 0) {
				for (i = 0; i < nodeIndex; i++) {
					indicador = indicador->pNextNode;
					if (i == nodeIndex) {
						break;
					}
				}
			}
		}
	}
	return indicador;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
 (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList *this, int nodeIndex) {
	return getNode(this, nodeIndex);
}

/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
 ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList *this, int nodeIndex, void *pElement) {

	int retornaAux = -1;
	Node *recienteNodo;

	if (this != NULL) {
		int longitud = ll_len(this);

		if (nodeIndex >= 0 && nodeIndex <= longitud) {
			recienteNodo = (Node*) malloc(sizeof(Node));
			recienteNodo->pElement = pElement;
			recienteNodo->pNextNode = NULL;
			if (recienteNodo != NULL) {

				if (nodeIndex == 0) {
					recienteNodo->pNextNode = this->pFirstNode;
					this->pFirstNode = recienteNodo;
				} else {
					Node *anterior = getNode(this, nodeIndex - 1);
					recienteNodo->pNextNode = anterior->pNextNode;
					anterior->pNextNode = recienteNodo;
				}
				this->size = longitud + 1;
				retornaAux = 0;
			}
		}
	}
	return retornaAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
 ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList *this, int nodeIndex, void *pElement) {
	return addNode(this, nodeIndex, pElement);
}

/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
 ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList *this, void *pElement) {
	int longitud;

	int returnAux = -1;

	if (this != NULL) {
		longitud = ll_len(this);
		addNode(this, longitud, pElement);
		returnAux = 0;
	}

	return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
 (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList *this, int index) {

	Node *indicador;

	void *returnAux = NULL;
	if (this != NULL) {
		indicador = getNode(this, index);
		if (indicador != NULL)

		{
			returnAux = indicador->pElement;
		}
	}

	return returnAux;
}

/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
 ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList *this, int index, void *pElement) {
	Node *cambioDeNodo;
	int longitud;
	int returnAux = -1;
	if (this != NULL) {
		longitud = ll_len(this);
		if (index >= 0 && index < longitud) {
			cambioDeNodo = getNode(this, index);
			if (cambioDeNodo != NULL) {
				cambioDeNodo->pElement = pElement;
				returnAux = 0;
			}
		}
	}

	return returnAux;
}

/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
 ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList *this, int index) {
	Node *recienteNodo;
	Node *siguienteNodo;
	Node *antiguoNodo;

	int longitud;
	int returnAux = -1;

	if (this != NULL) {
		longitud = ll_len(this);

		if (index >= 0 && index < longitud) {

			recienteNodo = getNode(this, index);

			if (recienteNodo != NULL) {
				siguienteNodo = getNode(this, index + 1);

				if (index == 0) {

					this->pFirstNode = siguienteNodo;

				} else {
					antiguoNodo = getNode(this, index - 1);

					if (antiguoNodo != NULL) {
						antiguoNodo->pNextNode = siguienteNodo;
					}
				}
			}
			this->size = longitud - 1;
			free(recienteNodo);
			returnAux = 0;
		}
	}

	return returnAux;
}

/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
 ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList *this) {
	int i;
	int longitud;
	int retornoTrasladado;
	int returnAux = -1;

	if (this != NULL) {

		longitud = ll_len(this);

		for (i = 0; i < longitud; i++) {
			retornoTrasladado = ll_remove(this, i);
			if (retornoTrasladado == -1) {
				returnAux = -1;
				break;
			}
			returnAux = 0;
		}
	}
	return returnAux;
}

/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
 ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList *this) {
	int returnAux = -1;

	if (this != NULL) {
		ll_clear(this);
		this->pFirstNode = NULL;
		free(this);
		returnAux = 0;
	}

	return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
 (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList *this, void *pElement) {
	Node *nodulo;
	int longitud;
	int i;
	int returnAux = -1;
	if (this != NULL) {
		longitud = ll_len(this);
		nodulo=this->pFirstNode;

		for (i = 0; i < longitud; i++) {
			if (nodulo->pElement == pElement) {
				returnAux = i;
			}
			nodulo = nodulo->pNextNode;
		}
	}

	return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
 ( 0) Si la lista NO esta vacia
 ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList *this) {

	int longitud;
	int returnAux = -1;
	if (this != NULL) {
		longitud = ll_len(this);
		if (longitud == 0) {
			returnAux = 1;
		} else {
			returnAux = 0;
		}
	}

	return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
 ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList *this, int index, void *pElement) {
	int retornaAux = -1;
	Node *recienteNodo;

	if (this != NULL) {
		int longitud = ll_len(this);

		if (index >= 0 && index <= longitud) {
			recienteNodo = (Node*) malloc(sizeof(Node));
			recienteNodo->pElement = pElement;
			recienteNodo->pNextNode = NULL;
			if (recienteNodo != NULL) {

				if (index == 0) {
					recienteNodo->pNextNode = this->pFirstNode;
					this->pFirstNode = recienteNodo;
				} else {
					Node *anterior = getNode(this, index - 1);
					recienteNodo->pNextNode = anterior->pNextNode;
					anterior->pNextNode = recienteNodo;
				}
				this->size = longitud + 1;
				retornaAux = 0;
			}
		}
	}
	return retornaAux;
}

/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
 (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList *this, int index) {
	void *pop;
	int longitud;
	void *returnAux = NULL;
	if (this != NULL) {
		longitud = ll_len(this);
		if (index >= 0 && index <= longitud) {
			pop = ll_get(this, index);
			ll_remove(this, index);
			returnAux = pop;
		}
	}
	return returnAux;
}

/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
 ( 1) Si contiene el elemento
 ( 0) si No contiene el elemento
 */
int ll_contains(LinkedList *this, void *pElement) {

	int indicador;
	int returnAux = -1;

	if (this != NULL) {
		indicador = ll_indexOf(this, pElement);
		if (indicador != -1) {
			returnAux = 1;
		} else {
			returnAux = 0;
		}
	}

	return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
 estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
 ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
 ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
 */
int ll_containsAll(LinkedList *this, LinkedList *this2) {
	void *indicador;
	int longitud;
	int i;
	int indicadorEquipador;
	int returnAux = -1;
	int indicadorFlag;
	if (this != NULL && this2 != NULL) {
		returnAux = 1;
		longitud = ll_len(this2);
		for (i = 0; i < longitud; i++) {
			indicador = ll_get(this2, i);
			indicadorEquipador = ll_contains(this, indicador);
			if (indicadorEquipador == 0) {
				indicadorFlag = 1;
			}
		}
		if (indicadorFlag == 1) {
			returnAux = 0;
		}
	}

	return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
 o (si el indice from es menor a 0 o mayor al len de la lista)
 o (si el indice to es menor o igual a from o mayor al len de la lista)
 (puntero a la nueva lista) Si ok
 */
LinkedList* ll_subList(LinkedList *this, int from, int to) {
	LinkedList *cloneArray = NULL;
	int j;

	if (this != NULL && from >= 0 && to <= ll_len(this) && to > from) {
		cloneArray = ll_newLinkedList();
		if (cloneArray != NULL) {
			for (j = from; j < to; j++) {
				ll_add(cloneArray, ll_get(this, j));
			}
		}

	}

	return cloneArray;
}

/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
 (puntero a la nueva lista) Si ok
 */
LinkedList* ll_clone(LinkedList *this) {
	LinkedList *cloneArray = NULL;
	if (this != NULL) {
		cloneArray = this;
	}

	return cloneArray;
}

/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
 ( 0) Si ok
 */
int ll_sort(LinkedList *this, int (*pFunc)(void*, void*), int order) {
	int returnAux = -1;
	int longitud;
	int i;
	int j;
	void *componenteAux;
	longitud = ll_len(this);
	if (this != NULL && pFunc != NULL && (order == 0 || order == 1)) {
		for (i = 0; i < longitud - 1; i++) {
			for (j = i + 1; j < longitud; j++) {
				if (order == 1) {
					if (pFunc(ll_get(this, i), ll_get(this, j)) > 0) {
						componenteAux = ll_get(this, i);
						ll_set(this, i, ll_get(this, j));
						ll_set(this, j, componenteAux);
					}
				} else {
					if (pFunc(ll_get(this, i), ll_get(this, j)) < 0) {
						componenteAux = ll_get(this, i);
						ll_set(this, i, ll_get(this, j));
						ll_set(this, j, componenteAux);
					}

				}
			}

		}
		returnAux = 0;
	}

	return returnAux;
}
