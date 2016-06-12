#ifndef __YLIST_H__
#define __YLIST_H__

#if defined(__cplusplus) || defined(c_plusplus)
extern "C" {
#endif /* __cplusplus || c_plusplus */

#include <stdbool.h>

/**
 * @typedef	ylist_t
 *		Double-linked list.
 * @field	first	First element of the list.
 * @field	last	Last element of the list.
 * @field	ptr	Pointer to the currently processed element.
 */
typedef struct ylist_s {
	struct ylist_elem_s *first;
	struct ylist_elem_s *last;
	struct ylist_elem_s *ptr;
} ylist_t;

/**
 * @typedef	ylist_elem_t
 *		Double-linked list element.
 * @field	data	Pointer to the list element.
 * @field	prev	Pointer to the previous element.
 * @field	next	Pointer to the next element.
 * @field	list	Pointer to the list which contains the element.
 */
typedef struct ylist_elem_s {
	void *data;
	struct ylist_elem_s *prev;
	struct ylist_elem_s *next;
	ylist_t *list;
} ylist_elem_t;

/**
 * @typedef	ylist_func_t
 *		Pointer to a function.
 * @param	elem_data	Pointer to the data in the list.
 * @param	user_data	Pointer to some user data.
 * @return	False if something went wrong.
 */
typedef bool (*ylist_func_t)(void *elem_data, void *user_data);

/**
 * @function	ylist_new
 *		Creates a new list.
 * @return	A pointer to the created list.
 */
ylist_t *ylist_new(void);

/**
 * @function	ylist_foreach
 *		Process a function on all elements of a list.
 * @param	list		Pointer to the list.
 * @param	func		Function to apply. The loop stops if the function returns false.
 * @param	user_data	Pointer to some user data.
 */
void ylist_foreach(ylist_t *list, ylist_func_t func, void *user_data);

/**
 * @function	ylist_rewind
 *		Put the internal pointer to the first element of the list.
 * @param	list	Pointer to the list.
 */
void ylist_rewind(ylist_t *list);

/**
 * @function	ylist_delete
 *		Destroy a list and all its elements.
 * @param	list		Pointer to the list.
 * @param	delete_function	Callback used to free the list elements.
 * @param	user_data	Pointer given to the delete function.
 * @return	true if the list was successfully deleted.
 */
bool ylist_delete(ylist_t *list, ylist_func_t delete_function, void *user_data);

/**
 * @function	ylist_add
 *		Add an element at the end of a list.
 * @param	list	Pointer to the list.
 * @param	data	Pointer to the added data.
 * @return	A pointer to the list element.
 */
ylist_elem_t *ylist_add(ylist_t *list, void *data);

/**
 * @function	ylist_put
 *		Add an element at the beginning of a list.
 * @param	list	Pointer to the list.
 * @param	data	Pointer to the added data.
 * @return	A pointer to the list element.
 */
ylist_elem_t *ylist_put(ylist_t *list, void *data);

/**
 * @function	ylist_get
 *		Remove the last element of a list.
 * @param	list	Pointer to the list.
 * @return	A pointer to the last element's data.
 */
void *ylist_get(ylist_t *list);

/**
 * @function	ylist_pop
 *		Remove the first element of a list.
 * @param	list	Pointer to the list.
 * @return	A pointer to the first element's data.
 */
void *ylist_pop(ylist_t *list);

/**
 * @function	ylist_swap
 *		Extract a list element from one list, and add it at the end of
 *		another list.
 * @param	elem	The element to swap.
 * @param	dest	The destination list.
 */
void ylist_swap(ylist_elem_t *elem, ylist_t *dest);

#if defined(__cplusplus) || defined(c_plusplus)
}
#endif /* __cplusplus || c_plusplus */

#endif /* __YLIST_H__ */