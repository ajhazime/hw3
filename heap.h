#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>

template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator()) : m(m), c(c) {}

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap() {}

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const{
		return m_heapList.empty();
	}

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const{
		return m_heapList.size();
	}

  void heapify(size_t idx);
	std::vector<T> m_heapList;

private:
  /// Add whatever helper functions and data members you need below

  int m;
  PComparator c;
  

};

// Add implementation of member functions here


// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("Heap is empty");


  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
  return m_heapList.front();


}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("Heap is empty");

  }

  
  std::swap(m_heapList[m_heapList.size() - 1], m_heapList[0]);

  m_heapList.pop_back();

	if(!empty()){
		heapify(0);
	}
 
  return;

}



template<typename T, typename PComparator>
void Heap<T,PComparator>::push(const T& item){

	m_heapList.push_back(item);
  size_t idx = m_heapList.size() - 1;
  
  
  while(idx > 0){
    size_t parentNode = (idx-1) / 2;
    if(c(m_heapList[idx], m_heapList[parentNode])){
      std::swap(m_heapList[idx], m_heapList[parentNode]);
      idx = parentNode;
    } else {break;}
  }
  return;
}




//Helper functions 
template<typename T, typename PComparator>
void Heap<T,PComparator>::heapify(size_t idx){

  
  size_t bestIndex = idx;
  for(int i = 0; i <= m; i++){
		size_t childNode = (2 * idx) + i;
		if(childNode < m_heapList.size() && c(m_heapList[childNode], m_heapList[bestIndex])){
			bestIndex = childNode;
		}
	}

	if (bestIndex != idx){
		std::swap(m_heapList[idx], m_heapList[bestIndex]);
		heapify(bestIndex);
	}

}

#endif

