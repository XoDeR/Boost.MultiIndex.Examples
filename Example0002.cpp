#include <iostream>
#include <string>
#include <boost/multi_index_container.hpp>
#include <boost/multi_index/random_access_index.hpp>
#include <boost/multi_index/ordered_index.hpp>
#include <boost/multi_index/mem_fun.hpp>

int main()
{
	typedef boost::multi_index_container<std::string, // std::string
		boost::multi_index::indexed_by<
			// std::vector
			boost::multi_index::random_access<>,										
			// std::multiset
			boost::multi_index::ordered_non_unique< boost::multi_index::identity<std::string> >, 
			boost::multi_index::ordered_non_unique< boost::multi_index::const_mem_fun<
															std::string, std::size_t, &std::string::length > > 
		>
	> Conainer;

	// sequenced - random access
	Conainer ItemNameContainer;
	ItemNameContainer.push_back( "Knife" );
	ItemNameContainer.push_back( "Gun" );
	ItemNameContainer.push_back( "Pistol" );
	ItemNameContainer.push_back( "Sword" );
	ItemNameContainer.push_back( "Sword" );
	ItemNameContainer.push_back( "MiniGun" );
	ItemNameContainer.push_back( "Pistol" );

	std::cout << "ItemNameContainer" << std::endl;
	std::for_each( ItemNameContainer.begin(), ItemNameContainer.end(), [](const std::string& s) { 
						std::cout << s << std::endl;
					} );
	std::cout << std::endl;


	// ordered_non_unique
	std::cout << "ItemNameContainer" << std::endl;
	
	Conainer::nth_index<1>::type& Index1 = ItemNameContainer.get<1>();
	std::for_each( Index1.begin(), Index1.end(), [](const std::string& s) { 
						std::cout << s << std::endl;
					} );
	std::cout << std::endl;

	// ordered_non_unique
	std::cout << "ItemNameContainer" << std::endl;

	Conainer::nth_index<2>::type& Index2 = ItemNameContainer.get<2>();
	std::for_each( Index2.begin(), Index2.end(), [](const std::string& s) { 
						std::cout << s << std::endl;
					} );
	std::cout << std::endl;
	return 0;
}