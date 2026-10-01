# Storage Advisor: HDD vs SSD Recommendation Tool
Part 2 (C++ Programming) of the Innovation Technology Life Cycle project.

**Group:** 12
**Section:** FCI4

## Group Members

| No. | Name | Student ID |
|---|---|---|
| 1 | Patmish Kumar A/L Pavala Malar Kannan | 253UC2422K |
| 2 | Nimalen A/L Rama Krishnan | 253UC242QD |
| 3 | Muhammad Muhyideen Bin Barakath Ali | 253UC243K8 |
| 4 | Roshan A/L Sahadevan | 253UC243CY |
| 5 | Dhishaal A/L Suntharesan | 253UC242R0 |

## 1. Connection to chosen technology
Part 1 covered the Hard Disk Drive using Christensen's Disruptive Innovation
model, from the 1956 IBM RAMAC to flash SSDs. This program applies that story
to a real choice: should a user buy an HDD or an SSD?

## 2. Purpose
Recommend HDD, SSD, or both based on the user's storage need, budget,
main use, and portability, and show how far storage has come since 1956.

## 3. Inputs and outputs

| Inputs | Outputs |
|---|---|
| Storage needed (GB) | Recommended drive type |
| Budget (RM) | Estimated cost |
| Main use (study, gaming, video editing, backup) | Cost comparison of HDD vs SSD |
| Portability needed (Y/N) | Number of 1956 RAMAC drives equal to the user's storage |

## 4. Logic design
- Main menu handled with a `switch` statement.
- Recommendation handled with `if / else if / else`:
  - Budget below HDD cost: tell the user the budget is too low.
  - Study: HDD, or SSD if portable and affordable.
  - Gaming: SSD if affordable, otherwise HDD.
  - Video editing: both if affordable, otherwise SSD or HDD.
  - Backup: HDD, or SSD if portable and affordable.

## 5. Price assumptions
HDD: RM 0.12/GB. SSD: RM 0.35/GB (course-project estimates, not live prices).

## 6. Development plan
Built over two weeks using regular Git commits.
Week 1: planning, skeleton, menu, input validation.
Week 2: recommendation logic, output, RAMAC comparison, testing.

## 7. Testing

Test cases run on the final program (price assumptions: HDD RM 0.12/GB, SSD RM 0.35/GB).

| # | Storage (GB) | Budget (RM) | Use | Portable | Expected result |
|---|---|---|---|---|---|
| 1 | 500 | 40 | Any | Any | Budget too low, cost RM 60.00 |
| 2 | 100 | 50 | Study | Y | SSD, RM 35.00 |
| 3 | 100 | 50 | Study | N | HDD, RM 12.00 |
| 4 | 500 | 200 | Gaming | N | SSD, RM 175.00 |
| 5 | 500 | 100 | Gaming | N | HDD, RM 60.00 |
| 6 | 1000 | 1000 | Video editing | N | BOTH, RM 470.00 |
| 7 | 500 | 100 | Backup | Y | HDD, RM 60.00 |

Menu option 3 with 500 GB shows about 102400 RAMAC drives.

### Input validation tests

| Input | Where | Expected result |
|---|---|---|
| `abc` | Any number or menu prompt | "Please enter a number / whole number", asks again |
| `-5` or `0` | Storage or budget | "Please enter a number greater than 0", asks again |
| `9` | Menu or use prompt | "Please choose between 1 and 4", asks again |
| `maybe` | Portable question | "Please type Y or N", asks again |
| Ctrl+Z then Enter | Any prompt | "Input ended. Goodbye!" and the program exits |

All tests passed.