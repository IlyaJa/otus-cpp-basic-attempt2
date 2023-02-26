#include <iostream>
#include <limits>
#include <chrono>
#include<vector>
#include<numeric>
#include <algorithm> 


void Funct();
double Time();

class IStatistics {
public:
	virtual ~IStatistics() {}

	virtual void update(const std::vector<double> &vec) = 0;
	virtual double eval() const = 0;
	virtual const char * name() const = 0;
};


class Min : public IStatistics {
public:
	Min() : m_min{std::numeric_limits<double>::max()} {
	}

	void update(const std::vector<double> &vec) override {
		m_min=*std::min_element(vec.begin(), vec.end());
	}

	double eval() const override {
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
	Max() : m_max{std::numeric_limits<double>::min()} {
	}

	void update(const std::vector<double> &vec) override {
		m_max=*std::max_element(vec.begin(), vec.end());
		}
	

	double eval() const override {
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
	Mean() : m_mean{ 0 } {
	}	
	double Sum=0;
	void update (const std::vector<double> &vec)override {
     
	 //double Sum = std::accumulate(vec.begin(), vec.end(), 0);
	 for (int i = 0; i < vec.size(); ++i) {
			Sum += vec[i];} 
	 
	 m_mean=Sum/vec.size();
	}

	double eval() const override {
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
	Std() :m_std{ 0 } {}
	
	
	void update(const std::vector<double>& vec) override {
		
		Mean m;
		m.update(vec);
		double mean = m.eval();		
		double Sum2 = 0;
		for (int i = 0; i < vec.size(); ++i)
		{
			Sum2 += pow((mean - vec[i]), 2);
		}
		m_std =sqrt( Sum2 / vec.size());
	}


	double eval() const override {
		return m_std;
	}

	const char* name() const override {
		return "std";
	}

private:
	double m_std;

};


int main() {

	std::vector<double> results;
	int number_results=10;
	for(int i=0; i<number_results; ++i){
		results.push_back(Time());
	}



	const size_t statistics_count = 4;
	IStatistics *statistics[statistics_count];

	statistics[0] = new Min{};
	statistics[1] = new Max{};
	statistics[2] = new Mean{};
	statistics[3] = new Std{};
	
	
		for (size_t i = 0; i < statistics_count; ++i) {
			statistics[i]->update(results);
		}
		
	

	// Handle invalid input data
	if (!std::cin.eof() && !std::cin.good()) {
		std::cerr << "Invalid input data\n";
		return 1;
	}

	// Print results if any
	for (size_t i = 0; i < statistics_count; ++i) {
		std::cout << statistics[i]->name() << " = " << statistics[i]->eval() <<" ms" <<std::endl;
	}

	// Clear memory - delete all objects created by new
	for (size_t i = 0; i < statistics_count; ++i) {
		delete statistics[i];
	}

	return 0;
}

void Funct() {
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
}