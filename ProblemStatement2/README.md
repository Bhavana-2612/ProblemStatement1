# Problem Statement 2

This folder contains the design files for the PCB evaluation board based on Nordic Semiconductor's nPM1100 Power Management IC.

---

## 📁 Files Included

- `Schematic.pdf`  
  ➤ Complete and labeled schematic of the nPM1100-based power management board.

- `BOM.csv`  
  ➤ Bill of Materials listing all SMD components used, along with values and footprints.

- `pcb_design/`  
  ➤ Contains layer-wise PCB layout plots:
  - `F.Cu.pdf` – Top copper routing
  - `F.SilkS.pdf` – Top silkscreen layer
  - `Edge.Cuts.pdf` – Board outline (35mm × 35mm)

---

## ✅ Design Specifications

- 📦 **Board Dimensions**: 35mm × 35mm  
- 🔌 **Output Voltage**: 3.0V (via VOUTB)  
- 🔋 **Charge Current**: 200mA (set using 5Ω resistor on ICHG pin)  
- 💡 **Indicators**:
  - CHG → LED for charging status
- 🔧 **Headers**:
  - J4 exposes: VOUTB, VBAT, CHG, OK, SYS-ON, GND

---

## ✅ Design Constraints Followed

- ✅ All components are **top-mounted SMDs**
- ✅ No SMDs smaller than **0402** or larger than **0805**
- ✅ Used only **open-source tools (KiCad)**
- ✅ PCB kept within the **35mm x 35mm** limit
- ✅ GND plane created using copper fill (F.Cu)
- ✅ Neat routing with minimal crossovers
- ✅ All required nets (VBUS, VBAT, VOUTB, CHG, GND, etc.) correctly routed and exposed

---

## 🛠️ Tools Used

- **KiCad 7.0**
- **3D Viewer** for PCB visualization
- **PDF Plotting** for schematic and board documentation

---

## 📌 Notes

- `readme.md` is provided to explain the purpose of each file and highlight design decisions.
- The board is suitable for evaluation/testing purposes as per the problem statement.

---

🧠 *Designed with attention to power integrity, signal routing, and contest constraints.*

