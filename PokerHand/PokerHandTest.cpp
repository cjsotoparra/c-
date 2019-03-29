//
// Created by Rick Mercer on 2019-03-20.
//

// Beginning of a Unit test for PokerHand and its overloaded < operator
#include "PokerHand.hpp"
#include "52Cards.hpp"
#include "catch.hpp"

TEST_CASE("testHighCard2") {
  PokerHand a(C3, C4, D6, D7, DQ);
  PokerHand b(C2, C5, C7, DJ, DK);

  REQUIRE(a < b);

}

TEST_CASE("testPairs2_3"){
	PokerHand pair(D2, H2, D3, S7, H6);
	PokerHand pair2(C2, S2, CQ, CK, CA);
	PokerHand pair3(C3, H3, H4, H5, S6);

	REQUIRE(HandRanking::ONE_PAIR == pair.getHandRank());
  	REQUIRE(pair2 < pair3);
	REQUIRE(pair2 < pair3);
	REQUIRE(pair < pair2);
	REQUIRE(pair < pair3);
	REQUIRE_FALSE(pair3 < pair);

	//check lower kicker
	PokerHand p(D3, D4, C6, S6, HQ);
	PokerHand p2(S2, S4, D6, H6, SQ);

	REQUIRE(p2 < p);

        //check mid kicker cards
        PokerHand p3(D3, D5, C6, S6, HQ);
        PokerHand p4(S3, S4, D6, H6, SQ);

        REQUIRE(p4 < p3);

        //check high kicker
        PokerHand p5(D3, D4, C6, S6, HK);
        PokerHand p6(S3, S4, D6, H6, SQ);

        REQUIRE(p6 < p5);


}

TEST_CASE ("AceLowStraight") {
  PokerHand a(CA, C2, S3, D4, H5); // Ace low straight
  PokerHand b(DK, HK, SK, D5, H6); // 3 of a kind
  REQUIRE(b < a);
}

TEST_CASE ("2Pair") {
	//pair
	PokerHand p(D3, D4, C6, S6, HQ);

	REQUIRE(HandRanking::ONE_PAIR == p.getHandRank());

	//b has higher kicker and both should be higher than a pair
	PokerHand a(CA, C2, SA, D2, H5);
	PokerHand b(DA, H2, HA, S2, S6);

	REQUIRE(HandRanking::TWO_PAIR == a.getHandRank());

	REQUIRE(p < a);
	REQUIRE(p < b);
	REQUIRE(a < b);
	REQUIRE_FALSE(b < a);

	//Tied
        PokerHand c(CA, C2, SA, D2, H5);
        PokerHand d(DA, H2, HA, S2, S5);
	REQUIRE_FALSE(c < d);

	//e has higher high pair
        PokerHand e(CA, C2, SA, D2, H5);
        PokerHand f(DK, H2, HK, S2, S6);

	REQUIRE(f < e);
}

TEST_CASE ("3OfAKindTest") {
        //Test order
        PokerHand p(D3, D4, C6, S6, HQ);
        PokerHand two(CA, C2, SA, D2, H5);
        PokerHand three(D2, H2, HA, S2, S6);

	REQUIRE(HandRanking::THREE_OF_A_KIND == three.getHandRank());
        REQUIRE(p < two);
        REQUIRE(p < three);
        REQUIRE(two < three);
        REQUIRE_FALSE(three < two);
	REQUIRE_FALSE(three < p);

        //Tied
        PokerHand c(CA, C3, SA, D2, HA);
        PokerHand d(DA, H3, HA, S2, SA);
        REQUIRE_FALSE(c < d);

        //e has higher 2nd side card
        PokerHand e(CA, C4, SA, D3, HA);
        PokerHand f(DA, H4, HA, S2, SA);

        REQUIRE(f < e);
}

TEST_CASE ("StraightTest") {
        //Test order
        PokerHand p(D3, D4, C6, S6, HQ);
        PokerHand two(CA, C2, SA, D2, H5);
        PokerHand three(D2, H2, HA, S2, S6);
        PokerHand c(C2, C3, S4, D5, HA); //low straight

	REQUIRE(p < c);
	REQUIRE(two < c);
	REQUIRE(three < c);

        //tied, e has higher straight
        PokerHand e(C10, CA, SQ, DJ, HK);

	REQUIRE(HandRanking::STRAIGHT == e.getHandRank());
        PokerHand f(D2, H3, HA, S4, S5);

	REQUIRE(HandRanking::STRAIGHT == f.getHandRank());
        REQUIRE(f < e);
	REQUIRE_FALSE(f < c);
}

TEST_CASE ("FLUSHTest") {
        //Test order
        PokerHand p(D3, D4, C6, S6, HQ);
        PokerHand two(CA, C2, SA, D2, H5);
        PokerHand three(D2, H2, HA, S2, S6);
        PokerHand c(C2, C3, S4, D5, HA); //low straight

	PokerHand fl(CQ, C8, C6, C4, C2); //flush
	REQUIRE(HandRanking::FLUSH == fl.getHandRank());
	REQUIRE(p < fl);
	REQUIRE(two < fl);
	REQUIRE(three < fl);
	REQUIRE(c < fl);

	PokerHand fl2(HQ, H8, H6, H4, H2); //flush 2

	//check tie
	REQUIRE_FALSE(fl2 < fl);

	//check tie with higher flush
	PokerHand fl3(SQ, S8, S6, S4, S3); //flush 3
	REQUIRE(fl < fl3);
}

TEST_CASE ("Full_HOUSE_TEST") {
        //Test order
        PokerHand p(D3, D4, C6, S6, HQ);
        PokerHand two(CA, C2, SA, D2, H5);
        PokerHand three(D2, H2, HA, S2, S6);
        PokerHand c(C2, C3, S4, D5, HA); //low straight
        PokerHand fl(CQ, C8, C6, C4, C2); //flush
	PokerHand full(CK, HK, SK, C10, S10); //full hosue

        REQUIRE(HandRanking::FULL_HOUSE == full.getHandRank());
        REQUIRE(p < full);
        REQUIRE(two < full);
        REQUIRE(three < full);
        REQUIRE(c < full);
	REQUIRE(fl < full);

        PokerHand full2(HK, CK, DK, H10, D10); //full 2

        //check tie
        REQUIRE_FALSE(full2 < full);
	REQUIRE_FALSE(full < full2);

	//full3 higher
	PokerHand full3(HA, CA, DA, H10, D10); //full 2

	REQUIRE(full < full3);

	//full4 higher 2nd pair
	PokerHand full4(DA, CA, SA, HJ, DJ); //full 4
	REQUIRE(full3 < full4);
}

TEST_CASE ("Four_Of_a_kind_TEST") {
        //Test order
        PokerHand p(D3, D4, C6, S6, HQ);
        PokerHand two(CA, C2, SA, D2, H5);
        PokerHand three(D2, H2, HA, S2, S6);
        PokerHand c(C2, C3, S4, D5, HA); //low straight
        PokerHand fl(CQ, C8, C6, C4, C2); //flush
        PokerHand full(CK, HK, SK, C10, S10); //full hosue
	PokerHand four(C8, DA, CA, SA, HA);	//four of a kind

        REQUIRE(HandRanking::FOUR_OF_A_KIND == four.getHandRank());
        REQUIRE(p < four);
        REQUIRE(two < four);
        REQUIRE(three < four);
        REQUIRE(c < four);
        REQUIRE(fl < four);
	REQUIRE(full < four);

        PokerHand four2(HK, CK, DK, SK, D10); //four2 

	//check tie
        REQUIRE(four2 < four);

        //four3 higher
        PokerHand four3(HA, CA, DA, SA, D8); //four 3

	//check same cards and kicker
	REQUIRE_FALSE(four3 < four);

        //four4 same as four but higher kicker
        PokerHand four4(HA, CA, DA, SA, D9); //four 4

        //check same cards and kicker
        REQUIRE(four < four4);

        //four5 same as four but lower kicker
        PokerHand four5(HA, CA, DA, SA, D7); //four 5

        //check same cards and kicker
        REQUIRE(four5 < four);
}

TEST_CASE ("StraightFlushTest") {
        //Test order
        PokerHand p(D3, D4, C6, S6, HQ);
        PokerHand two(CA, C2, SA, D2, H5);
        PokerHand three(D2, H2, HA, S2, S6);
        PokerHand c(C2, C3, S4, D5, HA); //low straight
        PokerHand fl(CQ, C8, C6, C4, C2); //flush
        PokerHand full(CK, HK, SK, C10, S10); //full hosue
        PokerHand four(C8, DA, CA, SA, HA);     //four of a kind
	PokerHand sF(C5, C6, C7, C9, C8);	//straight flush

        REQUIRE(HandRanking::STRAIGHT_FLUSH == sF.getHandRank());
        REQUIRE(p < sF);
        REQUIRE(two < sF);
        REQUIRE(three < sF);
        REQUIRE(c < sF);
        REQUIRE(fl < sF);
        REQUIRE(full < sF);
	REQUIRE(four < sF);

        PokerHand lSF(H2, H4, HA, H3, H5); //wheel straight flush 

        //check tie, sF is higher
        REQUIRE(lSF < sF);

        //sF2
        PokerHand sF2(D6, D5, D4, D2, D3); //sF2

        //check same straight flushes
        REQUIRE(sF2 < sF);
	REQUIRE(lSF < sF2);
}

TEST_CASE ("ROYAL_FLUSH_Test") {
        //Test order
        PokerHand p(D3, D4, C6, S6, HQ);
        PokerHand two(CA, C2, SA, D2, H5);
        PokerHand three(D2, H2, HA, S2, S6);
        PokerHand c(C2, C3, S4, D5, HA);	//low straight
        PokerHand fl(CQ, C8, C6, C4, C2); 	//flush
        PokerHand full(CK, HK, SK, C10, S10); 	//full hosue
        PokerHand four(C8, DA, CA, SA, HA);     //four of a kind
        PokerHand sF(C5, C6, C7, C9, C8);       //straight flush
	PokerHand rF (CA, CK, CQ, C10, CJ);	//Royal flush

        REQUIRE(HandRanking::ROYAL_FLUSH == rF.getHandRank());
        REQUIRE(p < sF);
        REQUIRE(two < sF);
        REQUIRE(three < sF);
        REQUIRE(c < sF);
        REQUIRE(fl < sF);
        REQUIRE(full < sF);
        REQUIRE(four < sF);
	REQUIRE(sF < rF);

        PokerHand lSF(H2, H4, HA, H3, H5); //wheel straight flush 

        //rF is higher
        REQUIRE(lSF < rF);

        //check tie
        PokerHand rF2(D10, DJ, DQ, DA, DK); //rF2

        //check same royal flushes
        REQUIRE(lSF < rF2);
        REQUIRE_FALSE(rF2 < rF);
	REQUIRE_FALSE(rF < rF2);
}

TEST_CASE ("High_Card_Test") {
        //Test order
	PokerHand hC(HK, SJ, C10, H6, D3);	//high card
        PokerHand p(D3, D4, C6, S6, HQ);
        PokerHand two(CA, C2, SA, D2, H5);
        PokerHand three(D2, H2, HA, S2, S6);
        PokerHand c(C2, C3, S4, D5, HA);        //low straight
        PokerHand fl(CQ, C8, C6, C4, C2);       //flush
        PokerHand full(CK, HK, SK, C10, S10);   //full hosue
        PokerHand four(C8, DA, CA, SA, HA);     //four of a kind
        PokerHand sF(C5, C6, C7, C9, C8);       //straight flush
        PokerHand rF (CA, CK, CQ, C10, CJ);     //Royal flush

        REQUIRE(HandRanking::HIGH_CARD == hC.getHandRank());
        REQUIRE(hC < p);
        REQUIRE(hC < two);
        REQUIRE(hC < three);
        REQUIRE(hC < c);
        REQUIRE(hC < fl);
        REQUIRE(hC < full);
        REQUIRE(hC < four);
        REQUIRE(hC < sF);
	REQUIRE(hC < rF);

        PokerHand hC2(DK, HJ, S10, C6, H2); //low kicker high card

        //rF is higher
        REQUIRE(hC2 < hC);

        //check tie
	PokerHand hC3(DK, HJ, S10, C6, H3); //same high card

        //check same royal flushes
        REQUIRE_FALSE(hC3 < hC);
        REQUIRE_FALSE(hC < hC3);

	//check mid kicker
        PokerHand hC4(DK, HJ, SQ, C6, H3); //mid kicker high card

        //hC4
        REQUIRE(hC < hC4);
        REQUIRE_FALSE(hC4 < hC);
}


