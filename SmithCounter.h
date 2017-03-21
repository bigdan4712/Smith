#ifndef SMITHCOUNTER_H
#define SMITHCOUNTER_H


class SmithCounter
{
  public:
	SmithCounter(int bits=2, int initialValue=0);
    void record_Branch(bool taken);
    void record_Branch_Taken();
    void record_Branch_Not_Taken();
    bool get_Prediction() const;
    int	 get_State() const;

  private:
    int number_Of_Bits;
    int state;
    int mask_Value;	// 2^number_Of_Bits -1
			// a fast way to mask off unused bits
						// set at creation
};

#endif // SMITHCOUNTER_H
