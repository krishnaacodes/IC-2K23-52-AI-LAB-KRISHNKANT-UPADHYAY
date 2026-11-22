# 🚦 Smart Traffic Signal Controller

### An Intelligent Rule-Based Traffic Management System Using Turbo Prolog 2.0

<p align="center">
  <img src="https://img.shields.io/badge/Language-Prolog-orange?style=for-the-badge" alt="Prolog">
  <img src="https://img.shields.io/badge/Compiler-Turbo%20Prolog%202.0-blue?style=for-the-badge" alt="Turbo Prolog">
  <img src="https://img.shields.io/badge/Environment-DOSBox-lightgrey?style=for-the-badge" alt="DOSBox">
  <img src="https://img.shields.io/badge/Project-AI%20Based-success?style=for-the-badge" alt="AI Based">
</p>

---

## 📖 About The Project

The **Smart Traffic Signal Controller** is a rule-based intelligent system developed using **Turbo Prolog 2.0**. It simulates traffic signal management by analyzing traffic conditions on four different roads and selecting the road that should receive the green signal.

Unlike conventional fixed-time traffic signals, this system uses logical rules and priority-based decision-making to evaluate traffic conditions.

The controller considers vehicle count, waiting time, emergency vehicles and road blockage to make its decision.

## ✨ Key Features

- 🚑 **Emergency Priority:** Gives the highest priority to roads carrying emergency vehicles.
- 🚗 **Traffic Analysis:** Evaluates vehicle counts across four roads.
- ⏱️ **Waiting Time:** Considers how long vehicles have been waiting.
- 🚧 **Road Blockage Detection:** Prevents blocked roads from being selected.
- ⚖️ **Priority-Based Selection:** Uses logical rules to determine the most suitable road.
- 🔄 **Tie-Breaking Mechanism:** Resolves equal priority scores using predefined road rankings.
- 📋 **Decision Explanation:** Displays the selected road and the reason behind the decision.

## 🧠 Decision-Making Process

The system follows a rule-based priority mechanism:

| Priority | Condition | Decision |
|:---:|---|---|
| 1 | Emergency vehicle detected | Highest priority |
| 2 | Road blocked | Not eligible |
| 3 | 20 or more vehicles | High priority |
| 4 | 10–19 vehicles | Medium priority |
| 5 | Fewer than 10 vehicles, waiting time ≥ 10 | Normal priority |
| 6 | Fewer than 10 vehicles, waiting time < 10 | Lower priority |

**Tie-breaking:** If multiple roads have equal scores, the system uses a predefined ranking: A → B → C → D.

## ⚙️ How It Works

```text
       START
         |
         ▼
  Read Traffic Data
         |
         ▼
 Check Emergency Vehicles
         |
         ▼
  Check Road Blockage
         |
         ▼
 Evaluate Traffic Density
         |
         ▼
 Calculate Priority Scores
         |
         ▼
 Select Highest Priority Road
         |
         ▼
 Display Green Signal
         |
         ▼
        END
```

## 🧪 Test Scenarios

### Test Case 1: Emergency Vehicle Detection

- Emergency vehicle is present on Road B.
- Emergency priority overrides normal traffic conditions.
- **Expected Output:** Road B receives the green signal.

### Test Case 2: Heavy Traffic

- Road C has 25 waiting vehicles.
- It has the highest eligible traffic priority.
- **Expected Output:** Road C receives the green signal.

### Test Case 3: Road Blockage

- Road A is marked as blocked.
- Roads B and C have equal priority.
- The predefined ranking resolves the tie.
- **Expected Output:** Road B receives the green signal.

## 📸 Project Output

The following screenshots demonstrate the execution of the three test scenarios.

| Test Case | Description |
|---|---|
| Test Case 1 | Emergency Vehicle Detection |
| Test Case 2 | Heavy Traffic Management |
| Test Case 3 | Road Blockage and Tie-Breaking |

> Screenshots will be added to the `screenshots/` directory.

## 🛠️ Built With

| Technology | Usage |
|---|---|
| Turbo Prolog 2.0 | Logic programming and execution |
| DOSBox | Running Turbo Prolog |
| Visual Studio Code | Writing and editing source code |
| GitHub | Source code hosting |

## 📂 Project Structure

```text
Smart-Traffic-Signal-Controller/
│
├── Smart-Traffic-Signal.PRO
├── README.md
│
└── screenshots/
    ├── test-case-1.png
    ├── test-case-2.png
    └── test-case-3.png
```

## 🚀 Getting Started

### Prerequisites

- DOSBox
- Turbo Prolog 2.0

### Execution Steps

1. Download or clone this repository.
2. Open DOSBox.
3. Mount the directory containing Turbo Prolog.
4. Launch `PROLOG.EXE`.
5. Load `Smart-Traffic-Signal.PRO`.
6. Select the Run option.
7. Observe the output for all three test cases.

## 🔮 Future Improvements

- Real-time traffic data integration.
- Dynamic green signal timing.
- Sensor-based vehicle detection.
- Emergency vehicle tracking.
- Coordination between multiple traffic intersections.

## 🎓 Academic Project

| Detail | Information |
|---|---|
| Project Title | Smart Traffic Signal Controller |
| Subject Area | Artificial Intelligence |
| Programming Language | Prolog |
| Compiler | Turbo Prolog 2.0 |
| Semester | MCA Semester 7 |
| Institution | International Institute of Professional Studies |

## 👨‍💻 Author

**Krishnkant Upadhyay**

MCA Semester 7  
IC-2K23-52
International Institute of Professional Studies

---

<p align="center">
  <b>🚦 Smart Logic. Better Traffic Decisions.</b>
  <br>
  Developed as an academic project using Turbo Prolog 2.0.
</p>