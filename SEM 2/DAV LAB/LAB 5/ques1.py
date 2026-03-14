import pandas as pd

# Read CSV file
df = pd.read_csv("Movies.csv")

# a) Movie with highest rating
highest_movie = df.loc[df["Rating"].idxmax()]
print("Movie with highest rating:")
print(highest_movie)

# b) Write Hindi movies to new CSV
hindi_movies = df[df["Language"] == "Hindi"]
hindi_movies.to_csv("HindiMovies.csv", index=False)

print("HindiMovies.csv file created successfully")