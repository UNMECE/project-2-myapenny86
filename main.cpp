#include <iostream>
#include <vector>
#include <fstream>
#include <string>

class Student {
protected:
	std::string firstName, lastName;
	double gpa;
	int graduationYear, enrolledYear;
	std::string graduationSemester, enrolledSemester, degreeLevel;

public:
	Student(): firstName("Unknown"), lastName("Unknown"), gpa(0.0), graduationYear(0), enrolledYear(0), graduationSemester("Unknown"), enrolledSemester("Unknown"), degreeLevel("Undergrad") {}

	virtual ~Student() {}

	void setName(const std::string& first, const std::string& last)
	{
		firstName = first;
		lastName = last;
	}

	void setGPA(double g)
	{
		gpa = g;
	}

	void setGraduationYear(int year)
	{
		graduationYear = year;
	}

	void setGraduationSemester(const std::string& semester)
	{
		graduationSemester = semester;
	}

	void setEnrolledYear(int year)
	{
		enrolledYear = year;
	}

	void setEnrolledSemester(const std::string& semester)
	{
		enrolledSemester = semester;
	}

	void setDegreeLevel(const std::string& level)
	{
		degreeLevel = level;
	}

	std::string getName() const
	{
		return firstName + " " + lastName;
	}
	
	double getGPA() const
	{
		return gpa;
	}

	int getGraduationYear() const
	{
		return graduationYear;
	}

	std::string getGraduationSemester() const
	{
		return graduationSemester;
	}

	int getEnrolledYear() const
	{
		return enrolledYear;
	}

	std::string getEnrolledSemester() const
	{
		return enrolledSemester;
	}

	std::string getDegreeLevel() const
	{
		return degreeLevel;
	}

	virtual void displayInfo(std::ofstream &outfile) const
	{
		outfile << "Name: " << getName() << "\n" << "GPA: " << gpa << "\n" << "Graduation: " << graduationSemester << " " << graduationYear << "\n" << "Enrolled: " << enrolledSemester << " " << enrolledYear << "\n" << "Level: " << degreeLevel << "\n";
	}
};

class artStudent:
public Student
{
	private:
		std::string artEmphasis;

	public:
		artStudent(): artEmphasis("Art Studio") {}

		void setArtEmphasis(const std::string& emphasis)
		{
			artEmphasis = emphasis;
		}

		std::string getArtEmphasis() const
		{
			return artEmphasis;
		}

		void displayInfo(std::ofstream &outfile) const
		{
			Student::displayInfo(outfile);
			outfile << "Art Emphasis: " << artEmphasis << "\n";
		}
};

class physicsStudent: 
public Student
{
	private:
		std::string concentration;

	public:
		physicsStudent(): concentration("Biophysics") {}
	
		void setConcentration(const std::string& conc)
		{
			concentration = conc;
		}

		std::string getConcentration() const
		{
			return concentration;
		}

		void displayInfo(std::ofstream &outfile) const
		{
			Student::displayInfo(outfile);
			outfile << "Concentration: " << concentration << "\n";
		}
};

int main()
{
	std::vector<artStudent *> art_students;
	std::vector<physicsStudent *> physics_students;

	for(int i = 0; i < 5; ++i)
	{
		artStudent *art = new artStudent;
		art->setName("ArtFirst" + std::to_string(i), "ArtLast" + std::to_string(i));
		art_students.push_back(art);
	}

	for(int i = 0; i <5; ++i)
	{
		physicsStudent *phys = new physicsStudent;
		phys->setName("PhysFirst" + std::to_string(i), "PhysLast" + std::to_string(i));
		physics_students.push_back(phys);
	}

	std::ofstream outfile("student_info.dat");
	if(outfile.is_open())
	{
		for(size_t i = 0; i < art_students.size(); ++i)
		{
			art_students[i]->displayInfo(outfile);
			outfile << "\n";
		}

		for(size_t i = 0; i < physics_students.size(); ++i)
		{
			physics_students[i]->displayInfo(outfile);
			outfile << "\n";
		}
		outfile.close();
	}else {
		std::cerr << "Unable to open file for writing.\n";
	}

	for(size_t i = 0; i < art_students.size(); ++i)
	{
		delete art_students[i];
	}

	for(size_t i = 0; i < physics_students.size(); ++i)
	{
		delete physics_students[i];
	}

	return 0;
}
