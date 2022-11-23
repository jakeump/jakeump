const modeToggle = document.getElementById("dark-mode-btn");
const darkModeClass = 'dark-mode';

const toggleMode = () => {
  setMode(document.body.classList.contains(darkModeClass));
}

const setMode = (mode) => {
  localStorage.setItem('mode', mode ? 'light' : 'dark');
  modeToggle.classList.toggle('fa-moon');
  modeToggle.classList.toggle('fa-sun');
  document.body.classList.toggle(darkModeClass, !mode);
}

modeToggle.addEventListener('click', toggleMode);

// default mode is dark. if mode is null, set to dark
(() => localStorage.getItem('mode') === null && localStorage.setItem('mode', 'dark'))();
// fetches stored mode, allows mode to remain on refresh
(() => localStorage.getItem('mode') === 'dark' && setMode(false))();