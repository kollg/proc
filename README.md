# proc - Galactic Dynamics Processing

This repository contains tools and Jupyter notebooks for processing and analyzing galactic dynamics data, particularly focusing on interactions between the Milky Way, Andromeda (M31), the Large Magellanic Cloud (LMC), and other nearby galaxies.

## About the Gaia Sky Survey Project

**Gaia** is a European Space Agency (ESA) space observatory launched in 2013 with the mission to create the most precise three-dimensional map of our galaxy, the Milky Way. The Gaia mission is one of the most ambitious astronomical projects ever undertaken.

### Key Features of Gaia:

- **Astrometry**: Measures the positions, distances, and proper motions of over 1 billion stars with unprecedented precision
- **Photometry**: Multi-band photometric measurements to determine stellar properties
- **Spectroscopy**: Radial velocity measurements for millions of stars
- **Data Releases**: Periodic public data releases (DR1, DR2, DR3, etc.) providing increasingly complete and precise stellar catalogs

### How Gaia Data is Used in This Repository:

The Gaia mission provides crucial observational data that is used throughout this repository's analyses:

1. **Proper Motions**: Gaia's precise measurements of stellar velocities help constrain models of galactic orbits and dynamics
2. **Distance Measurements**: Parallax measurements from Gaia allow accurate determination of distances to stars and stellar systems
3. **Kinematics**: Combined position and velocity data from Gaia enables detailed studies of galactic structure and evolution
4. **M31 (Andromeda) Studies**: Gaia data helps track the motion and properties of M31 as it approaches the Milky Way
5. **LMC/SMC Dynamics**: Observations of the Magellanic Clouds benefit from Gaia's precise astrometric measurements

## Repository Contents

### Jupyter Notebooks

- **GC_orbit.ipynb**: Analysis of globular cluster orbits
- **IC_density.ipynb**: Initial condition density profiles
- **agama_makeGC.ipynb**, **agama_test.ipynb**: Tests using the AGAMA library for galactic dynamics
- **galpy_makeGC.ipynb**: Globular cluster generation using galpy
- **make_NSC.ipynb**: Nuclear star cluster modeling
- **mass_loss_rate.ipynb**: Analysis of mass loss in stellar systems
- **petar_dispersion.ipynb**, **petar_test.ipynb**: Tests using PeTar N-body simulation code
- **remnant_mass.ipynb**: Stellar remnant mass calculations

### M31 Directory

Contains specialized notebooks for Andromeda (M31) galaxy analysis:
- M31 orbit and timing analysis
- MCMC fitting for LMC interactions
- Two-body and multi-galaxy dynamics
- Visualization and plotting tools

### C++ Tools

- **generate_3d_points.cpp**: Generates 3D particle distributions for simulations
- **test.cpp**: Performance testing for particle sorting and energy calculations

### Data Files

- **ndm.txt**: Dark matter particle data
- Various `.mp4` files: Visualizations of galactic interactions and dark matter distributions

## Dependencies

This repository uses several astronomical Python libraries:
- `galpy`: Galactic dynamics library
- `AGAMA`: Another action-based galaxy modeling architecture
- `astropy`: Core astronomy package
- Standard scientific Python stack (numpy, scipy, matplotlib)

## Related Resources

### Gaia Mission:
- **Official Website**: https://www.cosmos.esa.int/web/gaia
- **Gaia Archive**: https://gea.esac.esa.int/archive/
- **Documentation**: https://gea.esac.esa.int/archive/documentation/

### Scientific Context:
- Gaia's data is revolutionizing our understanding of galactic dynamics
- This repository leverages Gaia observations to constrain and validate simulation models
- The precise proper motions from Gaia enable accurate predictions of future galactic interactions

## Usage

Most analyses are contained in Jupyter notebooks. To run them:

```bash
jupyter notebook
```

Then navigate to the desired notebook and execute the cells.

For C++ tools:

```bash
g++ -o generate_3d_points generate_3d_points.cpp -std=c++11
./generate_3d_points
```

## License

See LICENSE file for details.

## Acknowledgments

This work makes use of data from the ESA mission Gaia, processed by the Gaia Data Processing and Analysis Consortium (DPAC).