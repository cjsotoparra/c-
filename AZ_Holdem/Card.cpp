#include <string>

// Model the Suit of a Poker Card
enum class Suit {
  CLUBS, DIAMONDS, HEARTS, SPADES
};

// TODO: add enum class Rank
enum class Rank{
 DEUCE = 2,
 THREE = 3,
 FOUR = 4,
 FIVE = 5,
 SIX = 6,
 SEVEN = 7,
 EIGHT = 8,
 NINE = 9,
 TEN = 10,
 JACK = 11,
 QUEEN = 12,
 KING = 13,
 ACE = 14
};

class Card{
	private:
		Rank rank;
		Suit suit;

	public:
		Card (Rank rank, Suit suit){
			this->rank = rank;
			this->suit = suit;
		}

		Rank getRank () const{
			return this->rank;
		}

		Suit getSuit() const{
			return this->suit;
		}

		int getValue() const{
			return static_cast<int>(rank);
		}

		std::string toString (){
			auto const club{"\xe2\x99\xa3"};
			auto const diamond{"\xe2\x99\xa6"};
			auto const heart{"\xe2\x99\xa5"};
			auto const spade{"\xe2\x99\xa0"};

			std::string str;

			//check if it's number of face card
			if(this->getValue()<=10){
				if(this->getSuit()== Suit::CLUBS){
					return std::to_string(this->getValue()) + club;
				}else if(this->getSuit() == Suit::HEARTS){
					return std::to_string(this->getValue()) + heart;
				}else if(this->getSuit() == Suit::DIAMONDS){
					return std::to_string(this->getValue()) + diamond;
				}else{
					return std::to_string(this->getValue()) + spade;
				}
			}else{
				//jacks
				if(this->getValue() == 11){

					str = "J";
					if(this->getSuit()== Suit::CLUBS){
                                        	return str + club;
  	                              	}else if(this->getSuit() == Suit::HEARTS){
        	                                return str + heart;
                	              	}else if(this->getSuit() == Suit::DIAMONDS){
                        	                return str + diamond;
                                	}else{
                                        	return str + spade;
                                	}

				//Queen
				}else if(this->getValue() == 12){

					str = "Q";
                                        if(this->getSuit()== Suit::CLUBS){
                                                return str + club;
                                        }else if(this->getSuit() == Suit::HEARTS){
                                                return str + heart;
                                        }else if(this->getSuit() == Suit::DIAMONDS){
                                                return str + diamond;
                                        }else{
                                                return str + spade;
                                        }

				//King
				}else if(this->getValue() == 13){

					str = "K";
                                        if(this->getSuit()== Suit::CLUBS){
                                                return str + club;
                                        }else if(this->getSuit() == Suit::HEARTS){
                                                return str + heart;
                                        }else if(this->getSuit() == Suit::DIAMONDS){
                                                return str + diamond;
                                        }else{
                                                return str + spade;
                                        }

				//Aces
				}else{
					str = "A";
                                        if(this->getSuit()== Suit::CLUBS){
                                                return str + club;
                                        }else if(this->getSuit() == Suit::HEARTS){
                                                return str + heart;
                                        }else if(this->getSuit() == Suit::DIAMONDS){
                                                return str + diamond;
                                        }else{
                                                return str + spade;
                                        }
				}

			}

		}

		bool operator < (const Card& other){

			return this->getValue() < other.getValue();
		}

};
