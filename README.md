# VelikaZabava 🎮

This C++ program is a helper tool for the online strategy game
**Travian**.\
It manages hourly production, ensures enough resources are reserved for
a **Great Celebration** (\~43h), and calculates how much extra can be
shipped to other villages.

## Features

-   Reads production data for multiple villages from `produkcija`
-   Accounts for the **Great Celebration** cost (`zabava`)
-   Reserves resources needed every ~43h
-   Balances extra production across villages
-   Outputs safe-to-send amounts per resource and per hour

## Input Format (`produkcija`)

Each line should contain:

    <VillageName> <Wood> <Clay> <Iron> <Crop> <TripsPerHour>

-   **VillageName** → Name of the Travian village\
-   **Wood/Clay/Iron/Crop** → Current stored resources\
-   **TripsPerHour** → Hourly merchant trips

### Example:

    VillageA 3500 5250 2625 6657 1
    VillageB 3500 3500 3500 5588 1

## Output (`rezultat`)

-   Adjusted production per village (after reserving for celebrations)
-   Total production
-   Amount to be sent away per resource per hour

### Example:

    VillageA 2811 4479 1883 6489
    VillageB 2811 2729 2758 5420

    Account production: 250000
    Sending each hour: 5000 4000 3000 2000

## Usage

1.  Prepare an input file named `produkcija` in the same directory.

2.  Compile the program:

    ``` bash
    g++ main.cpp -o travian-balance
    ```

3.  Run the program:

    ``` bash
    ./travian-balance
    ```

4.  Results will be saved to `rezultat`.

## Requirements

-   C++11 or newer
-   Input file `produkcija`

## Notes

-   The program assumes **Great Celebration** duration = `43:08:11`
    (fixed).
-   Celebration costs are defined in `zabava[]` at the start of the
    code.
-   Adjust those values if needed.
