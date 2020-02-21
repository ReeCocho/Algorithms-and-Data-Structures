#pragma once

/**
 * @file list.hpp
 * @brief List header file.
 * @author Connor J. Bramham (ReeCocho)
 */

/* Includes. */
#include <cstdint>

namespace ads
{
	/**
	 * Interface for a data type that implements the concept of a list.
	 * @tparam Type of data the list contains.
	 */
	template<typename T>
	class IList
	{
	public:

		/**
		 * Destructor.
		 */
		virtual ~IList() = default;

		/**
		 * Reference access operator.
		 * @param ind Index of the element to access.
		 * @return A reference to the element.
		 */
		virtual T& operator[](size_t ind) const = 0;

		/**
		 * Get the number of elements in the list.
		 * @return Number of elements in the list.
		 */
		virtual size_t get_size() const = 0;

		/**
		 * Check to see if the list contains a value.
		 * @param val Value to check for.
		 * @return The index of the value if it's in the list. Otherwise, return 'SIZE_MAX'.
		 */
		virtual size_t contains(const T& val) const = 0;

		/**
		 * Add a copy of some data as an element to the end of the list.
		 * @param data Data to append.
		 */
		virtual void append(const T& data) = 0;

		/**
		 * Move some data into the end of the list.
		 * @param data Data to append.
		 */
		virtual void append(T&& data) = 0;

		/**
		 * Add a copy of some data as an element to the front of the list.
		 * @param data Data to append.
		 */
		virtual void prepend(const T& data) = 0;

		/**
		 * Move some data into the front of the list.
		 * @param data Data to append.
		 */
		virtual void prepend(T&& data) = 0;

		/**
		 * Insert a copy of some data into the list at a specific index.
		 * @param data Data to insert.
		 * @param ind Index to insert the data at.
		 */
		virtual void insert(const T& data, size_t ind) = 0;

		/**
		 * Move some data into the list at a specific index.
		 * @param data Data to insert.
		 * @param ind Index to insert the data at.
		 */
		virtual void insert(T&& data, size_t ind) = 0;
		
		/**
		 * Remove the first instance of some given value from the list starting from the front.
		 * @param val Value to remove.
		 */
		virtual void remove(const T& val) = 0;

		/**
		 * Remove an element from the list by index.
		 * @param ind Index of the element to remove.
		 */
		virtual void remove_at(size_t ind) = 0;
	};
}