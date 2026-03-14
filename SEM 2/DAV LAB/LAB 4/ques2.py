import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt

# Load datasetr
df = pd.read_csv("cereal.csv")

# 1. Inspect missing values (-1)
print((df == -1).sum())

# 2. Average calories, sugar, fiber
print("Average Calories:", df["calories"].mean())
print("Average Sugar:", df["sugars"].mean())
print("Average Fiber:", df["fiber"].mean())

# 3. Top 5 cereals with highest sugar (bar plot)
top_sugar = df.sort_values("sugars", ascending=False).head(5)
sns.barplot(data=top_sugar, x="name", y="sugars")
plt.xlabel("Cereal")
plt.ylabel("Sugar")
plt.title("Top 5 Cereals with Highest Sugar")
plt.show()

# 4. Calories vs Rating
sns.scatterplot(data=df, x="calories", y="rating")
plt.xlabel("Calories")
plt.ylabel("Rating")
plt.title("Calories vs Rating")
plt.show()

# 5. Cold vs Hot cereals (calories)
sns.barplot(data=df, x="type", y="calories")
plt.xlabel("Cereal Type (C = Cold, H = Hot)")
plt.ylabel("Calories")
plt.title("Cold vs Hot Cereals (Calories)")
plt.show()

# 6. Healthier cereals (low sugar + high fiber)
healthy = df[(df["sugars"] < df["sugars"].mean()) &
             (df["fiber"] > df["fiber"].mean())]
print(healthy[["name", "sugars", "fiber"]])

# 7. Key visualization: Sugar vs Fiber
sns.scatterplot(data=df, x="sugars", y="fiber")
plt.xlabel("Sugar")
plt.ylabel("Fiber")
plt.title("Sugar vs Fiber in Cereals")
plt.show()