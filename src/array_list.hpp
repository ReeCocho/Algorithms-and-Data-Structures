#pragma once

/**
 * @file array_list.hpp
 * @brief Array list header file.
 * @author Connor J. Bramham (ReeCocho)
 */

/* Includes. */
#include "list.hpp"

namespace ads
{
	/** 
	 * Default capacity of array lists. 
	 * @note Must be greater than '0'.
	 */
	static const size_t DEFAULT_ARRAY_LIST_CAPACITY = 2;

	/**
	 * An implementation of a list using contiguous memory.
	 * @tparam Type of data the array list will contain.
	 */
	template<typename T>
	class ArrayList final : public IList<T>
	{
	public:

		/**
		 * Default constructor.
		 */
		ArrayList();

		/**
		 * Constructor.
		 * @param size Number of elements the array list should begin with.
		 * @param def Default value of the elements.
		 */
		ArrayList(size_t size, const T& def = {});

		/**
		 * Copy constructor.
		 * @param other Other array list.
		 */
		ArrayList(const ArrayList<T>& other);

		/**
		 * Move constructor.
		 * @param other Other array list.
		 */
		ArrayList(ArrayList<T>&& other) noexcept;

		/**
		 * Destructor.
		 */
		~ArrayList();

		/**
		 * Copy assignent.
		 * @param other Other array list.
		 * @return This array list.
		 */
		ArrayList<T>& operator=(const ArrayList<T>& other);

		/**
		 * Move assignment.
		 * @param other Other array list.
		 * @return This array list.
		 */
		ArrayList<T>& operator=(ArrayList<T>&& other) noexcept;

		/**
		 * Reserve a specific number of elements.
		 * @param cap New capacity.
		 */
		void reserve(size_t cap);

		// Implementation

		T& operator[](size_t ind) const override;
		size_t get_size() const override;
		size_t contains(const T& val) const override;
		void append(const T& data) override;
		void append(T&& data) override;
		void prepend(const T& data) override;
		void prepend(T&& data) override;
		void insert(const T& data, size_t ind) override;
		void insert(T&& data, size_t ind) override;
		void remove(const T& val) override;
		void remove_at(size_t ind) override;

	private:

		/** Current number of elements in the array list. */
		size_t m_size = 0;

		/** Maximum capacity of the array list. */
		size_t m_cap = DEFAULT_ARRAY_LIST_CAPACITY;

		/** Pointer to the first element in the array list. */
		T* m_data = nullptr;
	};
}

#include "array_list.imp.hpp"