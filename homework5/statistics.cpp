#include <iostream>
#include <limits>
//#include <chrono>
#include<vector>
#include<numeric>
#include <algorithm> 


//void Funct();
//double Time();

class IStatistics {
public:
	virtual ~IStatistics() {}

	virtual void update(double next) = 0;
	virtual double eval() = 0;
	virtual const char * name() const = 0;
};


class Min : public IStatistics {
public:
	Min() : m_min{std::numeric_limits<double>::max()} {
	}

	void update(double next) override {
		if(next<m_min){
			m_min = next;
		}
	}

	double eval() override {
		return m_min;
	}

	const char * name() const override {
		return "min";
	}

private:
	double m_min;
};

class Max : public IStatistics {
public:
	Max() : m_max{std::numeric_limits<double>::lowest()} {
	}

	void update(double next) override {
		if(next>m_max){
			m_max = next;
		}

	}
	

	double eval() override {
		return m_max;
	}

	const char * name() const override {
		return "max";
	}

private:
	double m_max;
};

class Mean : public IStatistics{
	public:	
	Mean() : m_mean{ 0 } {}
		
	double Sum=0;
	int size=0;
	void update (double next)override {
     ++size;
	 //double Sum = std::accumulate(vec.begin(), vec.end(), 0);
	 Sum+=next;
	 
	 m_mean=Sum/size;
	}

	double eval() override {
		return m_mean;
	}

	const char * name() const override {
		return "mean";}
	
	private:
	double m_mean;
};

class Std : public IStatistics 
{
public:
	Std() : m_std{ 0 }, resulst{} {}
	//Std() : std::vector<double> resulst(0) {}
	
	void update(double next) override {
		resulst.push_back(next);
	}
		
		/*Mean m;
		m.update(next);
		double mean = m.eval();		
		double Sum2 = 0;
		for (int i = 0; i < vec.size(); ++i)
		{
			Sum2 += pow((mean - vec[i]), 2);
		}
		m_std =sqrt( Sum2 / vec.size());
	}*/


	double eval() override {
		double Sum2=0;
	    Sum2=std::accumulate(resulst.begin(), resulst.end(), Sum2);
		double mean2=Sum2/size(resulst);
		double Sum3=0;
		for (int i = 0; i < size(resulst); ++i)
		{
			Sum3 += pow((mean2 - resulst[i]), 2);
		}
		m_std =sqrt( Sum3 /size(resulst));
		return m_std;
	}

	const char* name() const override {
		return "std";
	}

private:
	double m_std;
	std::vector<double> resulst;

};


int main() {

	/*std::vector<double> results;
	int number_results=10;
	for(int i=0; i<number_results; ++i){
		results.push_back(Time());
	}*/



	const size_t statistics_count = 4;
	IStatistics *statistics[statistics_count];

	statistics[0] = new Min{};
	statistics[1] = new Max{};
	statistics[2] = new Mean{};
	statistics[3] = new Std{};
	double val=0;

	while(std::cin>>val){
		for (size_t i = 0; i < statistics_count; ++i) {
			statistics[i]->update(val);
		}
	}
		
	

	// Handle invalid input data
	if (!std::cin.eof() && !std::cin.good()) {
		std::cerr << "Invalid input data\n";
		return 1;
	}

	// Print results if any
	for (size_t i = 0; i < statistics_count; ++i) {
		std::cout << statistics[i]->name() << " = " << statistics[i]->eval()<<std::endl;
	}

	// Clear memory - delete all objects created by new
	for (size_t i = 0; i < statistics_count; ++i) {
		delete statistics[i];
	}

	return 0;
}

/*void Funct() {
	int a = 0;
	int b = 100000000;
	while (--b) {
		a = b;
	}
}

double Time() {
	auto startTime = std::chrono::system_clock::now();
	Funct();
	auto endTime = std::chrono::system_clock::now();
	std::chrono::duration<double> duration = (endTime - startTime);
	double result = duration.count();
	return result;
}*/