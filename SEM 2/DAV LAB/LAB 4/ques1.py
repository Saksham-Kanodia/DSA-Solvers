import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt

# Load dataset
df = pd.read_csv("mtcars.csv")
print(df.describe())
print(df.dtypes)

# Cylinders vs MPG
sns.scatterplot(data=df, x="cyl", y="mpg")
plt.xlabel("Cylinders")
plt.ylabel("Miles per Gallon (mpg)")
plt.title("Cylinders vs MPG")
plt.show()

# Horsepower vs MPG
sns.scatterplot(data=df, x="hp", y="mpg")
plt.xlabel("Horsepower")
plt.ylabel("Miles per Gallon (mpg)")
plt.title("Horsepower vs MPG")
plt.show()

# Manual vs Automatic vs MPG
sns.boxplot(data=df, x="am", y="mpg")
plt.xlabel("Transmission (0 = Automatic, 1 = Manual)")
plt.ylabel("Miles per Gallon (mpg)")
plt.title("Transmission vs MPG")
plt.show()

# Power vs Fuel Efficiency
sns.scatterplot(data=df, x="hp", y="mpg")
plt.xlabel("Horsepower")
plt.ylabel("Miles per Gallon (mpg)")
plt.title("Power vs Fuel Efficiency")
plt.show()