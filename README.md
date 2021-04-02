# Cpp_DemographicStatistics

Abstraction, encapsulation, polymorphism, inheritance, unit testing, visitor classes, reading in data, calculating demographic statistics using C++

In this project, I applied various OOP techniques to explore statistics to answer questions such as:  
- Which state has the lowest rated hospitals?  
- Is there any correlation between % with college degrees and hosptial quality?
- Which cities have the most Americans over 65?

## File Descriptions

I created a hierarchy that begins with **placeData.h**, with children **demogData.h**, **financeData.h**, and **hospitalData.h**.

**demogData.h** has child **comboDemogData.h** and **hospitalData.h** has children **cityHospitalData.h** and **comboHosptialData.h**

The csv files are read in through **parse.h**. The csv files are from https://corgis-edu.github.io/corgis/csv/

**rating.h** is a class to allow encapsulation for hospital ratings (out of 5 stars).

The vistior functions generate reports on the demographic without needing to add to the classes.

The stats files allow various statistics to calculated, such as mean, standard deviation, correlation, and covariance.

The tests files check the code for any logical errors in the code.

## Results

### Correlation Coefficients:
- Over 65 Count and Total Retirement Spending= 0.869
- College degree count and Total Edcuation Spending = 0.956
- Number of Hospitals and Total Hospital Spending = 0.762
