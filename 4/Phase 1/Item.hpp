#pragma once
#include <string>
#include "Seller.hpp"

using namespace std;


class Item
{
public:
	int get_id() const { return id; };
	string get_name() const { return name; };
	Seller* get_seller()  { return seller_username; };
	string  get_seller_username()  { return seller_username->get_username(); };
	string get_category() const { return category; };
	string get_date() const { return date; };
	int get_quantity() const { return quantity; };
	int get_purchased_count() const { return purchased_count; };
	int get_refund_percentage() const { return refund_percentage; };
	static void Increase_Id() { current_registerd_item++; };
	static int get_current_Id() { return current_registerd_item; };
	Item(string _name,Seller* _seller_username,string _category, string _date, double _price, int _quantity, int _purchased_count,int _refund_percentage)
		:name(_name), category(_category), date(_date), price(_price), quantity(_quantity),
		purchased_count(_purchased_count) {
		if (_refund_percentage != 0) { refund_percentage = _refund_percentage; }
		seller_username =_seller_username ;
		id = current_registerd_item;
		Increase_Id();
	}
	void decrease_quantity(int count);
	void change_quantity(int count);
	void change_price(double _price);
	void increase_quantity(int count);
	bool is_id_same(int _id);
	bool is_name_same(string _name);
	bool is_seller_username_same(string _seller_unsername);
	double get_price() const { return price; };
	bool operator <(const Item* s2) const;
	void print_info();
	void print_info_seller();
	void decrease_purchased_quantity(int count);
private:

	int id;
	string name;
	Seller* seller_username;
	string category;
	string date;
	double price;
	int quantity;
	int purchased_count;
	double refund_percentage = 0;
	static int current_registerd_item ;
};
