#pragma once

/**
 * @file array_list.imp.hpp
 * @brief Array list header implementation file.
 * @author Connor J. Bramham (ReeCocho)
 */

/* Includes. */
#include <new>
#include <cassert>

namespace ads
{
	template<typename T>
	ArrayList<T>::ArrayList()
	{
		// Allocate memory
		m_data = new T[m_cap];
		assert(m_data != nullptr);
	}

	template<typename T>
	ArrayList<T>::ArrayList(size_t size, const T& def) :
		m_size(size)
	{
		// Double the capcacity until it's greater than or equal to the size requested
		while (m_cap <= m_size)
			m_cap *= 2;

		// Allocate memory
		m_data = new T[m_cap];
		assert(m_data != nullptr);

		// Construct elements
		try
		{
			for (size_t i = 0; i < m_size; ++i)
				new(&m_data[i])T(def);
		}
		catch (...)
		{
			// Avoid memory leak
			delete[] m_data;
		}
	}

	template<typename T>
	ArrayList<T>::ArrayList(const ArrayList<T>& other)
	{
		*this = other;
	}

	template<typename T>
	ArrayList<T>::ArrayList(ArrayList<T>&& other) noexcept
	{
		*this = std::move(other);
	}

	template<typename T>
	ArrayList<T>::~ArrayList()
	{
		// Call destructor on every element
		for (size_t i = 0; i < m_size; ++i)
			m_data[i].~T();

		// Free memory
		delete[] m_data;
	}

	template<typename T>
	ArrayList<T>& ArrayList<T>::operator=(const ArrayList<T>& other)
	{
		// Call destructor on every element
		for (size_t i = 0; i < m_size; ++i)
			m_data[i].~T();

		// Free memory
		delete[] m_data;

		// Update members
		m_size = other.m_size;
		m_cap = other.m_cap;
		
		// Allocate memory
		m_data = new T[m_cap];
		assert(m_data != nullptr);

		// Copy elements
		for (size_t i = 0; i < m_size; ++i)
			m_data[i] = std::copy(other);

		return *this;
	}

	template<typename T>
	ArrayList<T>& ArrayList<T>::operator=(ArrayList<T>&& other) noexcept
	{
		// Call destructor on every element
		for (size_t i = 0; i < m_size; ++i)
			m_data[i].~T();

		// Free memory
		delete[] m_data;

		// Update members
		m_size = std::move(other.m_size);
		m_cap = std::move(other.m_cap);
		m_data = std::move(other.m_data);

		// Reset members
		other.m_size = 0;
		other.m_cap = 0;
		other.m_data = nullptr;

		return *this;
	}

	template<typename T>
	void ArrayList<T>::reserve(size_t cap)
	{
		// New capacity must be greater
		if (cap < m_cap)
			return;

		// Update capacity
		m_cap = cap;

		// Allocate new memory
		T* new_data = new T[m_cap];
		assert(new_data != nullptr);

		// Move elements
		for (size_t i = 0; i < m_size ++i)
			new(&new_data[i])T(std::move(m_data[i]));

		// Call destructor on old elements
		for (size_t i = 0; i < m_size ++i)
			m_data[i].~T();

		// Delete old data
		delete[] m_data;

		// Update data
		m_data = new_data;
	}

	template<typename T>
	T& ArrayList<T>::operator[](size_t ind) const
	{
		assert(ind < m_size);
		return m_data[ind];
	}

	template<typename T>
	size_t ArrayList<T>::get_size() const
	{
		return m_size;
	}

	template<typename T>
	size_t ArrayList<T>::contains(const T& val) const
	{
		// Perform a linear search on the elements
		for (size_t i = 0; i < m_size; ++i)
			if (m_data[i] == val)
				return i;

		return SIZE_MAX;
	}

	template<typename T>
	void ArrayList<T>::append(const T& data)
	{

	}

	template<typename T>
	void ArrayList<T>::append(T&& data)
	{

	}
	
	template<typename T>
	void ArrayList<T>::prepend(const T& data)
	{

	}
	
	template<typename T>
	void ArrayList<T>::prepend(T&& data)
	{

	}
	
	template<typename T>
	void ArrayList<T>::insert(const T& data, size_t ind)
	{

	}
	
	template<typename T>
	void ArrayList<T>::insert(T&& data, size_t ind)
	{

	}
	
	template<typename T>
	void ArrayList<T>::remove(const T& val)
	{

	}
	
	template<typename T>
	void ArrayList<T>::remove_at(size_t ind)
	{

	}
}