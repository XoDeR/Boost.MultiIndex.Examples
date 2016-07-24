#include <iostream>
#include <string>
#include <boost/multi_index_container.hpp>
#include <boost/multi_index/sequenced_index.hpp>
#include <boost/multi_index/ordered_index.hpp>

int main()
{
	typedef boost::multi_index_container<std::string, // std::string
		boost::multi_index::indexed_by<
			// std::list
			boost::multi_index::sequenced<>,										
			// std::multiset 
			boost::multi_index::ordered_non_unique< boost::multi_index::identity<std::string> > 
		>
	> Conainer;

	// sequenced
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


	// set - O(logN)
	std::cout << "Pistol : " << Index1.count("Pistol") << std::endl;
	std::cout << std::endl;


	std::cout << "ItemNameContainer Sword" << std::endl;
	// set - O(logN)
	Index1.erase("Sword");
		
	std::for_each( ItemNameContainer.begin(), ItemNameContainer.end(), [](const std::string& s) { 
						std::cout << s << std::endl;
					} );
	std::cout << std::endl;

	return 0;
}