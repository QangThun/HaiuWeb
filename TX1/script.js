// script.js

// Scroll to section when button clicked
function scrollToSection(id) {
    document.getElementById(id).scrollIntoView({ behavior: 'smooth' });
}

// Fade-in animation when element appears on scroll
const fadeEls = document.querySelectorAll('.fade-in');

function revealOnScroll() {
    const windowHeight = window.innerHeight;
    fadeEls.forEach(el => {
        const elementTop = el.getBoundingClientRect().top;
        if (elementTop < windowHeight - 100) {
            el.classList.add('visible');
        }
    });
}

window.addEventListener('scroll', revealOnScroll);
window.addEventListener('load', revealOnScroll);
