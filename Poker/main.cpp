#include "52Cards.hpp"
#include "PokerHand.hpp"
#include <iostream>
using namespace std;

int main(){

	PokerHand a(C3, D3, D6, D7, C4); //there is a pair

	cout << a.isPair(a.getMyHand()) << endl; //return 1

	PokerHand b(C3, D3, D6, C6, DQ); //2 pair

        cout << b.is2Pair(b.getMyHand()) << endl; //return 1

        PokerHand c(C3, C4, D6, C7, DQ); //not 2 pair

        cout << c.is2Pair(c.getMyHand()) << endl; //return 0

	/*************check 3 of a kind ****************/
	cout << "Three of a kind test" << endl;
        PokerHand d(C7, D7, S7, C6, DQ); //3 of a kind

        cout << d.isThreeOfAKind(d.getMyHand()) << endl; //return 1

        PokerHand e(C7, D7, D6, S7, DQ); //3 of a kind

        cout << e.isThreeOfAKind(e.getMyHand()) << endl; //return 1

        PokerHand de(C7, D7, D6, S2, DQ); //3 of a kind
        cout << de.isThreeOfAKind(de.getMyHand()) << endl; //return 1


        /*************check Straight ****************/
        cout << "Striaght Test" << endl;
        PokerHand f(D3, C2, S4, D5, C6); //straight

        cout << f.isStraight(f.getMyHand()) << endl; //return 1

        PokerHand g(C10, DJ, DQ, SK, DA); //ace high

        cout << g.isStraight(g.getMyHand()) << endl; //return 1

        PokerHand h(C2, D3, D4, S5, DA); //low ace

        cout << h.isStraight(h.getMyHand()) << endl; //return 1

        PokerHand j(C2, D3, D4, S5, DQ); //no straight

        cout << j.isStraight(j.getMyHand()) << endl; //return 0

        /*************check Flush ****************/
        cout << "Flush Test" << endl;
        PokerHand k(D2, D3, D4, D5, DQ); //flush
	cout << k.isFlush(k.getMyHand()) << endl;

        PokerHand l(D2, D3, D4, D5, SQ); //not flush
        cout << l.isFlush(l.getMyHand()) << endl;

        /*************check Full House ****************/
        cout << "Full House" << endl;
        PokerHand m(DK, SK, CK, D2, S2); //full house
        cout << m.isFullHouse(m.getMyHand()) << endl;

        PokerHand n(DK, SK, CK, D2, SQ); //not fULL HOUSE
        cout << n.isFullHouse(n.getMyHand()) << endl;

	/*************isFourOfAKind ****************/
        cout << "isFourOfAKind" << endl;
        PokerHand o(DK, SK, CK, D2, SK); //four of a kind
        cout << o.isFourOfAKind(o.getMyHand()) << endl;

	PokerHand p(DK, SK, CK, D2, SQ); //not four of a kind
        cout << p.isFourOfAKind(p.getMyHand()) << endl;

        /*************isStraightFlush ****************/
        cout << "isStraightFlush" << endl;
        PokerHand o2(DA, D3, D2, D4, D5); //straight flush ace low
        cout << o2.isStraightFlush(o2.getMyHand()) << endl;

        PokerHand p2(SA, SK, SQ, SJ, S10); //straight flush ace high
        cout << p2.isStraightFlush(p2.getMyHand()) << endl;

        PokerHand o3(D4, D6, D5, D3, D7); //straight flush
        cout << o3.isStraightFlush(o3.getMyHand()) << endl;

        PokerHand p3(SA, SK, SQ, S9, S10); //no straight flush
        cout << p3.isStraightFlush(p3.getMyHand()) << endl;

	cout << (o3 < p3) << endl;
	cout << (p3 < o3) << endl;
	return 0;
}
