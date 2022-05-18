#include <string>
#include <queue>
#include <list>
#include <memory>
#ifndef _PROCESS_H
#define _PROCESS_H


class Process
{
public:
	Process()
		: pid(""), arrivalTime(0.0), burstTime(0.0), priority(0) {}
	Process(std::string pid, double arrivalTime, double burstTime, unsigned priority)
		: pid(pid), arrivalTime(arrivalTime), burstTime(burstTime), priority(priority) {}
	Process(const Process& rhs)
		: pid(rhs.pid), arrivalTime(rhs.arrivalTime), burstTime(rhs.burstTime), priority(rhs.priority) {}

	void SetPid(const std::string& pid) { this->pid = pid; }
	void SetArrivalTime(const double arrivalTime) { this->arrivalTime = arrivalTime; }
	void SetBurstTime(const double burstTime) { this->burstTime = burstTime; }
	void SetPriority(const unsigned priority) { this->priority = priority; }

	std::string GetPid() const { return pid; }
	double GetArrivalTime() const { return arrivalTime; }
	double GetBurstTime() const { return burstTime; }
	unsigned GetPriority() const { return priority; }

	Process& operator=(const Process& rhs);

	// ���μ��� ��ü�� 'double'�� �����ڷ� ���񽺽ð��� ����
	// ��) Process P1 ( burstTime = 10 )
	//     P1 -= 3
	// ���) P1 ( burstTime = 7 )
	Process& operator-=(const double time);
	Process& operator+=(const double time);
	const Process operator-(const double time);
	const Process operator+(const double time);

private:
	std::string pid;		// ���μ��� ID
	double arrivalTime;		// �����ð�
	double burstTime;		// ���񽺽ð�
	unsigned priority;		// �켱����
};


auto CMP_PROCESS = [](const Process& lhs, const Process& rhs) { return lhs.GetArrivalTime() > rhs.GetArrivalTime(); };

// ���� �ð��� ���� ���� ���μ����� ���� ���� �켱������ ���� ���μ��� ť
using ProcessQueue = std::priority_queue<Process, std::vector<Process>, decltype(CMP_PROCESS)>;
// ���μ��� ť ���� �Լ�
std::unique_ptr<ProcessQueue> CreateProcessQueue();

// ��Ʈ ��Ʈ�� ���μ��� ID�� �� ���μ����� ���� ������ ���
using GanttChart = std::list<std::pair<std::string, double>>;

#endif