template<typename T, typename Container>
class vector_iterator {
	
//---------------ITERATOR TYPEDEFS (iterator traits)---------------------------------
	public:
		typedef std::random_access_iterator_tag		iterator_category;
		typedef typename T::value_type				value_type;
		typedef typename T::difference_type			difference_type;
		typedef typename T::pointer					pointer;
		typedef typename T::reference				reference;

//---------------ITERATOR CONSTRUCTORS-----------------------------------------------

	public:
		vector_iterator(void) : _ptr(NULL) {}
		vector_iterator(pointer ptr) : _ptr(ptr) {}

		vector_iterator() // new copy constructor for const

		vector_iterator(const vector_iterator &src) : _ptr(src._ptr) {}
		~vector_iterator() {};

//---------------ITERATOR OPERATOR OVERLOADS----------------------------------------

		vector_iterator& operator=(vector_iterator const &rhs) {
			_ptr = rhs._ptr;
			return (*this);
		}
		
		reference operator*(void) { return (*_ptr); }

		pointer operator->(void) { return (_ptr); }

		reference operator[](difference_type offset) { return(*((*this) + offset)); }
		
		bool operator==(vector_iterator const &rhs) const {
			return (_ptr == rhs._ptr);	
		}
		
		bool operator!=(vector_iterator const &rhs) const {
			return (_ptr != rhs._ptr);
		}

		bool operator<(vector_iterator const &rhs) const {
			return (_ptr < rhs._ptr);
		}

		bool operator<=(vector_iterator const &rhs) const {
			return (_ptr <= rhs._ptr);
		}

		bool operator>(vector_iterator const &rhs) const {
			return (_ptr > rhs._ptr);
		}

		bool operator>=(vector_iterator const &rhs) const {
			return (_ptr >= rhs._ptr);
		}

		// above: move out of member functions?
		
		vector_iterator &operator++(void) {
			_ptr++;
			return (*this);
		}
		
		vector_iterator operator++(int) {
			vector_iterator ret(*this);
			_ptr++;
			return (ret);
		}

		vector_iterator &operator--(void) {
			_ptr--;
			return (*this);
		}
		
		vector_iterator operator--(int) {
			vector_iterator ret(*this);
			_ptr--;
			return (ret);
		}

		vector_iterator operator+(difference_type offset) const {

			return (vector_iterator(_ptr + offset));
		}
		
		difference_type  operator+(vector_iterator rhs) const {

			return (_ptr + rhs._ptr);
		}

		vector_iterator  operator-(difference_type offset) const {

			return (vector_iterator(_ptr - offset));
		}

		difference_type  operator-(vector_iterator rhs) const {

			return (_ptr - rhs._ptr);
		}

		vector_iterator &operator+=(difference_type offset) {
			_ptr += offset;
			return (*this);
		}
		
		vector_iterator &operator-=(difference_type offset) {
			_ptr -= offset;
			return (*this);
		}

	private:
		pointer _ptr;
};